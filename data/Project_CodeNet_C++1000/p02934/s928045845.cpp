#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    double ans = 0.0;
    for (int i = 0; i < N; i++) {
        ans += 1.0 / A[i];
    }
    ans = 1.0 / ans;

    cout << fixed << setprecision(12) << ans << endl;
}