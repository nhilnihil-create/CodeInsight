#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, two = 1;
    for(int i = 0; i < 60; i++){
        ll zero = 0, one = 0;
        for(int j = 0; j < n; j++){
            if(a[j] & (1LL << i)) one++;
            else zero++;
        }
        ll tmp = (zero * one) % MOD * two % MOD;
        ans = (ans + tmp) % MOD;
        two = (two * 2) % MOD;
    }
    cout << ans << endl;
}
