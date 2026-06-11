/*
     “You just can’t beat the person who won’t give up.”
                                                            */
#include <bits/stdc++.h>
#define ll long long
#define oo 0x3f3f3f3f3f3f3f3fLL
#define lp(i,n) for(int i = 0;i < int(n);i++)
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
const int maxn=2e5+5;
const  double EPS = 1e-9;
const int mod = 1e9+7;

inline void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
ll sum(ll i) {
  return ((i * (i + 1)) / 2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    File();
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += i * sum(n / i);
    }
    cout << ans << endl;
}
