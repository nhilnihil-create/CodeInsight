#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
#include<string.h>
#include<cstring>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll inf = ll(1e9 + 7);

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> cnt(k + 1);
    for (int i = k; i >= 1; i--) {
        ll ki = ll(k / i);
        ll cnti = modpow(ki, ll(n), inf);
        int ii = 2 * i;
        while (ii <= k) {
            cnti -= cnt[ii];
            cnti=(cnti+inf)%inf;
            ii += i;
        }
        cnt[i] = cnti;
        ans += ll(i) * cnti % inf;
        ans %= inf;
    }
    cout << ans << endl;
}