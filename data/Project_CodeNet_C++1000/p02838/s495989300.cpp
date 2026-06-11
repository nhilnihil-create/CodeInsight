#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>inline bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const ll MOD = 1e9+7;
vecl res(60);

ll modpow(ll a, ll n) {
    ll ans = 1;
    REP(i,n) {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    vecl A(N); REP(i,N) cin >> A[i];
    REP(i,N) {
        REP(j,60) {
            if((A[i]>>j)&1) res[j]++;
        }
    }
    ll ans = 0;
    REP(i,60) {
        ll a = (res[i] * (N-res[i]))%MOD;
        ans += a*modpow(2,i);
        ans %= MOD;
    }
    cout << ans << endl;
}