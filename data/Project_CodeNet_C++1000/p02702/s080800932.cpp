#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 2019;

ll modpow(ll a, ll n, ll mod = MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main(){
    string S; cin >> S;
    ll N = S.size();
    vector<ll> DP(N);
    DP[N-1] = S[N-1]-48;
    for(int i = N-2; i >= 0; i--){
        DP[i] =DP[i+1] + modpow(10, N-1-i) * (S[i]-48);
        DP[i] %= MOD;
    }
    ll ans = 0;
    map<ll, ll> M;
    rep(i, N) M[DP[i]]++;
    M[0]++;
    for(auto m : M) ans += (m.second*(m.second-1))/2;
    cout << ans << endl;



}