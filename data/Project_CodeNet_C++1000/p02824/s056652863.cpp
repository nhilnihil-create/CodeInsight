#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vll A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());

    ll sum = A[P-1];
    vector<bool> ok(N, false);
    rep(i, P) ok[i] = true;
    for(ll i = P; i < N; i++) {
        if(A[i] == A[i-1]) {
            ok[i] = ok[i-1];
        }
        else if(A[i]+M >= A[P-1]) {
            ll res = V - (N-1-i+P);
            if((i-P+1)*(A[i]+M)-sum >= M*res) ok[i] = true;
        }
        sum += A[i];
    }
    ll ans = 0;
    rep(i, N) if(ok[i]) ans++;
    cout << ans << endl;
}
