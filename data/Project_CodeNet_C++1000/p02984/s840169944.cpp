#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;

void solve() {
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int acc = 0;
    for (int i = 0; i < N-2; ++i) {
        acc = -(A[i] + acc);
    }
    int x = A[N-2] + acc;
    int x_last = (A[N-1] + x) / 2;
    vector<int> B(N);
    B[N-1] = x_last*2;
    for (int i = N-2; i >= 0; --i) {
        x_last = A[i] - x_last;
        B[i] = x_last*2;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", B[i]);
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
