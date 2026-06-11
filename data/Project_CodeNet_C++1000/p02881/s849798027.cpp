#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

vector<ll> divisor(ll N) {
    vector<ll> RES;
    for (ll I = 1; I*I <= N; I++) {
        if (N%I == 0) {
            RES.push_back(I);
            if (I != N/I) RES.push_back(N/I);
        }
    }
    return RES;
}

int main() {
    ll n; cin >> n;
    vector<ll> div = divisor(n);
    ll ans = INF;
    for (auto x : div) {
        ans = min(ans, x + n/x - 2);
    }
    cout << ans << endl;
    return 0;
}