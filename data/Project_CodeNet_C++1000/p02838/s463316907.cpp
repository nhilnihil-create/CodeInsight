#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

int main() {
    ll N, B = 60;
    cin >> N;
    vl A(N), cnts(B);
    rep(i,N) {
        cin >> A[i];
        rep(j,B) cnts[j] += (A[i]>>j) & 1;
    }
    ll ans = 0;
    rep(j,B) (ans += (cnts[j]*(N-cnts[j]))%MOD * ((ll)pow(2,j)%MOD)) %= MOD;
    cout << ans << endl;
    return 0;
}
