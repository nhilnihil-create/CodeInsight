#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main(){
    int N;
    cin >> N;
    vector<ll> count(65);
    ll res = 0;
    rp(i, 0, N) {
        ll a;
        cin >> a;
        for(int i = 0; i < 60; i++) {
            if(a & (1ll<<i)) count[i]++;
        }
    }
    rp(i, 0, 60) {
        res += (1ll<<i) % MOD * count[i] % MOD * (N - count[i]) % MOD;
        res %= MOD;
    }
    printf("%lld\n", res);
    return 0;
}