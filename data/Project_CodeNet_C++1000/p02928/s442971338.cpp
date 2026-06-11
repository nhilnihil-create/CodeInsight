#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;


int main() {
    int n; cin >> n;
    ll k; cin >> k;
    V<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll tmp = (k * (k - 1) / 2) % MOD;
    for(int i = 0; i < n; i++){
        int f = 0, b = 0;
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]) f++;
        }
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]) b++;
        }
        ans = (ans + (b * k) + ((b + f) * tmp)) % MOD;
    }

    cout << ans << endl;

    return 0;
}
