#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    int A[N];
    rep(i, N) cin >> A[i];

    int R = 0, G = 0, B = 0;
    ll ans = 1;
    rep(i, N) {
        if (R == A[i]) {
            if (R==G && R == B) ans *= 3;
            else if (R==G && R>B) ans *= 2;
            R++;
        } else if (G == A[i]) {
            if (G == B) ans *= 2;
            G++;
        } else if (B == A[i]) {
            B++;
        } else {
            ans *= 0;
            break;
        }
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}