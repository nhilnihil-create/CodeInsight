
// Problem: A - Don't be late
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define FAST_IO                                                                                                        \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define endl "\n"
#define db1(x) cout << #x << " = " << x << '\n';
#define db2(v)                                                                                                         \
    for (auto &x : v)                                                                                                  \
        cout << x << " ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

int main()
{
    FAST_IO;
    int d, s, t;
    cin >> d >> t >> s;
    double time = (double)d/s;
    if(time<=t)
    	cout<<"Yes";
    else
    	cout<<"No";
    return 0;
}