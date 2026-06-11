/*
author : seryu
title : Tokio Marine 2020 A_"Nickname"
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

void solve()
{
	string s;
	cin >> s;
	cout << s.substr(0,3) << endl;
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
