/*
author : seryu
title : ABC170D_"Not Divisible"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,j,n) for(int i = j; i < n; i++)
#define mreps(i,j,n) for(int i = j; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

//divisors: enumerate divisors
set<ll> divisors(ll n)
{
	set<ll> res;
	for (ll i = 1; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			res.insert(i);
			res.insert(n / i);
		}
	}
	return res;
}

void solve()
{
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> a(n);
	int a_ma = 0;
	rep(i, n) 
	{
		cin >> a[i];
		mp[a[i]]++;
		chmax(a_ma, a[i]);
	}
	sort(all(a));
	vector<bool> indivisible(a_ma+1, true);
	int ans = 0;
	rep(i, n)
	{
		if(indivisible[a[i]])
		{
			if(mp[a[i]] == 1)ans++;
			int j = 1;
			while (j * a[i] <= a_ma)
			{
				indivisible[j*a[i]] = false;
				j++;
			}
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
