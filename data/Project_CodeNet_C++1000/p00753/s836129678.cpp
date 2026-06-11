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
#include<list>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define fori(i,k,n) for(int i=k;i<(int)n;i++)
using namespace std;
const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
const int dX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dY[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
struct XY
{
	int x;
	int y;
};


/*
(char)'1' - (int)48 = (int)1;


*/


int a[300000] = {};
int main()
{
	for (int i = 2; i < 300000; i++)a[i] = 1;
	for (int i = 2; i < 300000; i++)
	{
		if (a[i] == 1)
		{
			for (int l = i * 2; l < 300000; l += i)
			{
				a[l] = 0;
			}
		}
	}
	for (int i = 2; i < 300000; i++)a[i] += a[i - 1];

	int n;
	cin >> n;
	while (n != 0)
	{
		cout << a[2*n] - a[n] << endl;
		cin >> n;
	}
}