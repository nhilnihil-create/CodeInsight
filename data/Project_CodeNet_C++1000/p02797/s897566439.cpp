#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N, K, S;
    cin >> N >> K >> S;
    if (S < 1000000000) {
        rep(i, K) {
            cout << S << " ";
        }
        rep2(i, K, N) {
            if (i == N-1) {
                cout << S+1 << endl;
                return 0;
            }
            else {
                cout << S + 1 << " ";
            }
        }
    }
    else {
        rep(i, K) {
            cout << S << " ";
        }
        rep2(i, K, N) {
            if (i == N-1) {
                cout << 1 << endl;
            }
            else {
                cout << 1 << " ";
            }
        }
    }
}