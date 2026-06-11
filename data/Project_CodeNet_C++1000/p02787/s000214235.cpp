#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){

    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<ll> dp(h + 10, MAX);
    rep(i, h) {
        rep(j, n) {
            if (i + 1 > a[j]) {
                dp[i + 1] = min(dp[i + 1], dp[i + 1 - a[j]] + b[j]);
            } else {
                dp[i + 1] = min(dp[i + 1], b[j]);
            }
        }
    }
    cout << dp[h] << endl;

}