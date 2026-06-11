/*
author : seryu
title : ABC175C_"Walking Takahashi"
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
    ll x, k, d;
    cin >> x >> k >> d;
    ll r = x % d;
    ll q = x / d;
    if (abs(q) > k)
    {
        cout << abs(x) - d * k << endl;
    }
    else
    {
        k -= abs(q);
        if (k % 2 == 0)
        {
            cout << abs(r) << endl;
        }
        else
        {
            cout << min(abs(r+d), abs(r-d)) << endl;
        }
    }    
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
