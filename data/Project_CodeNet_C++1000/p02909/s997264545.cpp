#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	unordered_map<string, string> mp;
	mp["Sunny"]  = "Cloudy";
	mp["Cloudy"] = "Rainy";
	mp["Rainy"]  = "Sunny";
	string s;
	cin >> s;
	cout << mp[s];
}

int main()
{
	fastio;
	solve();

	return 0;
}