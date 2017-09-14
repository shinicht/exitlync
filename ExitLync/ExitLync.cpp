// ExitLync.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define IDS_TBPOPUP_CLOSE               40148

HWND GetLyncWindowHandle()
{
	WCHAR	title[256];
	WCHAR	classname[256];

	HWND hwnd = GetTopWindow(NULL);
	do {
		if (GetWindowLong(hwnd, GWL_HWNDPARENT) != 0 || !IsWindowVisible(hwnd)) {
			continue;
		}
		GetClassName(hwnd, classname, 256);
		//GetWindowText(hwnd, title, 256);
		if (lstrcmpW(L"CommunicatorMainWindowClass", classname) == 0) {
			GetWindowTextW(hwnd, title, 256);
			return(hwnd);
		}
	} while ((hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)));
	return( (HWND)NULL);
}


int main()
{
	HWND lynchwnd;
	lynchwnd = GetLyncWindowHandle();
	if (lynchwnd) {
		SendMessage(lynchwnd, WM_SETFOCUS, 0, 0);
		SendMessage(lynchwnd, WM_CLOSE, 0, 0);
	}
    return 0;
}

