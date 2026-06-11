#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<iomanip>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<list>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repp(i,k,n) for(int i=k;i<(int)n;i++)
#define F first
#define S second
using namespace std;
const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
const int dX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dY[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
struct XY
{
	int x;
	int y;
};
int in()
{
	int x;
	cin >> x;
	return x;
}

/*
(char)'1' - (int)48 = (int)1;
　1111181
*/
////////////////////////////////////////////////////
int a[200];
int n;
bool se(int now,int m,int j)
{
	
	if (now == m)return true;
	if (j == n)return false;
	if (se(now + a[j], m, j + 1) || se(now, m, j + 1))return true;
}


int main()
{
	
	cin >> n;
	rep(i, n)cin >> a[i];
	int q;
	cin >> q;
	rep(i, q)
	{
		int m;
		cin >> m;
		if (se(0, m, 0))cout << "yes" << endl;
		else cout << "no" << endl;
	}
}