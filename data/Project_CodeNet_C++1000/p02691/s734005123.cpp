#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll B[N]{};
    ll C[N]{};
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (i + A[i] < N) {
            B[i + A[i]]++;
        }
        if (i - A[i] > 0) {
            C[i - A[i]]++;
        }
    }
    for (int i = 1; i < N - 1; i++) {
        ans += B[i] * C[i];
    }
    cout << ans << "\n";
    return 0;
}