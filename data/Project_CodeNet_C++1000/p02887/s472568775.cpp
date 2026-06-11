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
	string s;
	cin >> n >> s;
	vector<char> t(n);
	for(int i = 0; i < n; ++i)
	{
		t[i] = s[i];
	}
	t.erase(unique(t.begin(), t.end()), t.end());
	cout << t.size();
}

int main()
{
	fastio;
	solve();

	return 0;
}