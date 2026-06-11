#include <bits/stdc++.h>
using namespace std;
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int x = ceil(n / 1.08);
	if (floor(x * 1.08) == n)	cout << x << endl;
	else	cout << ":(";
	return 0;
}