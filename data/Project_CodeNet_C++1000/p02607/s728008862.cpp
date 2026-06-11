#include <iostream>
#include<bits/stdc++.h>
#define input ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define dl endl
#define ft first
#define sc second
using namespace std;
int n, a[105],cnt=0;
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	input;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] & 1 && i & 1) ++cnt;
	}
	cout << cnt;
}