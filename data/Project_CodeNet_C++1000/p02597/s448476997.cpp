/*
author : seryu
title : ABC174D_"Alter Alter"
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r_cnt = 0;
    rep(i, n)if(s[i] == 'R')r_cnt++;
    int ans = r_cnt;
    rep(i, r_cnt)if(s[i] == 'R')ans--;
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
