#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <string>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <functional>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 1145141919
#define ll long long
//#define scanf scanf_s
bool p[260000];
int s[260000];

int main()
{
	REP(i, 260000) p[i] = true;
	p[0] = p[1] = false;
	for (int i = 2; i*i <= 250000; i++)
	{
		if (p[i] == true)
		{
			for (int j = 2; j*i <= 250000; j++)
			{
				p[i*j] = false;
			}
		}
	}
	s[1] = 0;
	FOR(i,2, 250000)
	{
		if (p[i] == true) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
	}
	int n;
	while (cin >> n,n)
	{
		cout << s[2*n]-s[n] << endl;
	}
	return 0;
}