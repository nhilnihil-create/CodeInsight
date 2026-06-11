#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll a, b, c, d;

ll solve(ll x){
    ll cnt = lcm(c, d);
    ll ans = x/cnt * (cnt - cnt/c - cnt/d + 1);
    x %= cnt;
    ans += x - x/c - x/d;
    return ans;
}


int main() {
    cin >> a >> b >> c >> d;
    cout << solve(b) - solve(a-1) << endl;
}