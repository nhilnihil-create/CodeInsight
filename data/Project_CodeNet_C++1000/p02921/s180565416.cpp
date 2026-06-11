#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rrep(i, n) for(ll i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(V) rep(i, V.size()) cout << V[i] << " ";
const ll INF = 1LL << 61;
const ll MOD = 1000000007 /*988244353*/;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, h, x, y, z, p, q, m, n, t, r, k, w, l, ans, i, j;
string S, T;
vl A, B;
void solve() {
    rep(i,3){
        ans+=(S[i]==T[i]);
    }
    cout<<ans<<endl;
}
int main() {
    // cout<<fixed<<setprecision(15);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>S>>T;
    solve();
}