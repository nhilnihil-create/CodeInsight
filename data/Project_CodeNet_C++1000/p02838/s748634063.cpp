#include <iostream>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main () {
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];

    ll ans = 0;
    int mod = 1000000007;
    rep(i, 60) {
        ll b = 1ll << i;
        int z = 0;
        rep(j, N) {
            if ((A[j] & b) == 0) {
                z++;
            }
        }
        ans = (ans + b % mod * z % mod * (N - z) % mod) % mod;
    }

    cout << ans << endl;
    return 0;
}
