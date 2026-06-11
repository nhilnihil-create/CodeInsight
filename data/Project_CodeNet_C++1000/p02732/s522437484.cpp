#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll> >;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    ll n; cin >> n;
    ll ans = 0;
    vector<ll> A(n), S(n+1, 0);
    rep(i, n) cin >> A[i];
    rep(i, n) S[A[i]]++;
    rep(i, n+1) {
        if(S[i] > 1) ans += S[i] * (S[i]-1) / 2;
    }
    rep(i, n) {
        cout << ans - S[A[i]] + 1 << endl;
    }

    return 0;
}