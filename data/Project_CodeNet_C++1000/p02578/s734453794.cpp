/*
	submission # - User: herp_sy
	https://atcoder.jp/contests/

	coding: utf-8
	lang: C++ (GCC 9.2.1)
*/

#include <bits/stdc++.h>
using namespace std;

// utility of stdin,stdout
#define _CRT_SECURE_NO_WARNINGS
#define OUT cout << 
#define BR << endl
#define RET return 0
#define TLong long long
#define TBMod int(1e9+7)

int main(int argc, char const *argv[])
{
	// DON'T CHANGE
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	// here
	TLong n;
	vector<TLong> a;
	TLong in;
	TLong ans = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> in;
		a.push_back(in);
	}
	for (int i = 1; i < n; i++)
	{
		if(a[i - 1] > a[i]){
			ans += (a[i - 1] - a[i]);
			a[i] += (a[i - 1] - a[i]);
		}
	}
	OUT(ans) BR;
	RET;
}
