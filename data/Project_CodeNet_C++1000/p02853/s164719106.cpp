#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll x,y;
    cin >> x >> y;
    ll res = 0;
    if(x==3) res += 100000;
    if(x==2) res += 200000;
    if(x==1) res += 300000;
    if(y==3) res += 100000;
    if(y==2) res += 200000;
    if(y==1) res += 300000;
    if(x==1 && y==1) res += 400000;
    cout << res << endl;
}