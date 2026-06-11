#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

int main() {
    string S;
    cin >> S;
    ll N = S.length() + 1;
    vi A(N);
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == '<') {
            A[i + 1] = A[i] + 1;
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        if (S[i] == '>') {
            A[i] = max(A[i], A[i + 1] + 1);
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i];
    }
    cout << ans << endl;
}
