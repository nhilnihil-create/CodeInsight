/*
author : seryu
title : ABC138E_"Strings of Impurity"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
	string s,t;
	cin >> s >> t;
	int n = sz(s);
	int m = sz(t);
	map<char, int> mp;
	rep(i, n)mp[s[i]]++;
	rep(i, m)
	{
		if(mp[t[i]] == 0)
		{
			cout << -1 << endl;
			return;
		}
	}
	vector<vector<int>> alp(26);
	rep(i, n) alp[s[i]-'a'].push_back(i);
	ll ans = 0;
	int j = 0;
	while(j < m)
	{
		int i = ans % n;
		if(lower_bound(all(alp[t[j]-'a']), i)-alp[t[j]-'a'].begin() == sz(alp[t[j]-'a']))
		{
			ans += n-i;
		}
		else
		{
			int x = *lower_bound(all(alp[t[j]-'a']), i);
			ans += x+1-i;
			j++;
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
