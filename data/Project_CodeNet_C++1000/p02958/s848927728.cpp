#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	vector<int> sorted_p(p);
	sort(sorted_p.begin(), sorted_p.end());

	int differ_num = 0;
	for(int i = 0; i < n; ++i)
	{
		if(p[i] != sorted_p[i]) differ_num++;
	}
	cout << (differ_num <= 2 ? "YES" : "NO");
}

int main()
{
	fastio;
	solve();

	return 0;
}