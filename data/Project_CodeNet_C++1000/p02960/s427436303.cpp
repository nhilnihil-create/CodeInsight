#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;
string s;
const int mod = 1e9 + 7;
const int N = 13;
ll a[N]; // remainder 0 - 12
ll b[N];

int main() {
    cin >> s;
    int n = s.length();
    a[0] = 1;
    for (int k = 0; k < n; ++k) {
        if (s[k] == '?') {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < 10; ++j) {
                    int cur = (i * 10 + j) % N;
                    b[cur] += a[i];
                }
            }
        } else {
            int o = s[k] - '0';
            for (int i = 0; i < N; ++i) {
                int cur = (i * 10 + o) % N;
                b[cur] += a[i];
            }
        }
        for (int i = 0; i < N; ++i) {
            a[i] = b[i] % mod;
        }
        memset(b, 0, sizeof b);
    }
    cout << a[5] << endl;
    return 0;
}
