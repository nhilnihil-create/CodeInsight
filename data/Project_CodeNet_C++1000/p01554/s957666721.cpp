#include<cmath>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<map>
#include<utility>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fori(i,k,n) for(int i=k;i<(int)n;i++)
using namespace std;
const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
const int dX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dY[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
/*
(char)'1' - (int)48 = (int)1;


*/


int main()
{
	string a[300];
	int n;
	int m; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	bool now = true;
	for (int i = 0; i < m; i++)
	{
		string x;
		cin >> x;
		bool ok=false;
		for (int l = 0; l < n; l++)
		{
			if (a[l] == x)
			{
				ok = true; break;
			}
		}
		if (ok)
		{
			if (now)
			{
				cout << "Opened by " << x << endl;
				now = false;
			}
			else
			{
				cout << "Closed by " << x << endl;
				now = true;
			}
		}
		else
		{
			cout << "Unknown " << x << endl;
		}
	}
}