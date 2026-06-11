// AISING2020A.cpp
//#include "pch.h"
#include <iostream>
#include <numeric>
using namespace std;
int main()
{
	int L, R, d;
	cin >> L>> R>> d;
	int f[110] = {};
	int now = 0;
	int ans = 0;
	while(now<=100)
	{
		now += d;
		f[now] = 1;
	}
	for (int i = L; i <= R; i++) {
		if (f[i] == 1) ans++;
	}
	cout << ans << endl;
}
