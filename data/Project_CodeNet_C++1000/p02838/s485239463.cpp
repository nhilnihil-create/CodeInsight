#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int N;  cin >> N;
    ll *a = new ll[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];

    ll mod = 1e9+7;

    vector<vector<int> > b(N, vector<int>(60));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 60; j++) {
            b[i][j] = a[i] % 2;
            a[i] /= 2;
        }
    }
    

    vector<vector<ll> > p(N, vector<ll>(60)), q(N, vector<ll>(60));
    for (int k = 0; k < 60; k++) {
        p[N-1][k] = (1-b[N-1][k]);
        q[N-1][k] = b[N-1][k];

        for (int i = N-1; i > 0; i--) {
            p[i-1][k] = p[i][k] + (1-b[i-1][k]);
            q[i-1][k] = q[i][k] + b[i-1][k];
        }
    }
    

    ll ans = 0, tmp = 1;
    for (int k = 0; k < 60; k++) {
        ans += tmp * p[0][k] % mod * q[0][k] % mod;
        ans %= mod;
        tmp *= 2;
        tmp %= mod;
    }

    cout << ans << endl;
    return 0;
}