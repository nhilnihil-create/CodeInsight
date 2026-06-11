#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 2;
int N;

void solve() {
    cin >> N;
    vector<int> A(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i+1];
    }

    int m = 0;
    vector<int> B(N+1, 0);
    for (int i = N; i >= 1; --i) {
        int a = A[i];
        int s = 0;
        for (int j = 2 * i; j <= N; j += i) {
            s += B[j];
        }
        if (s % 2 != a) {
            ++m;
            B[i] += 1;
        }
    }
    cout << m << endl;
    if (m > 0) {
        for (int i = 1; i <= N; ++i) {
            if (B[i] == 1) {
                printf("%d ", i);
            }
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
