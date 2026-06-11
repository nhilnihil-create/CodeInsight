#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    int res = A[N - 1] - A[0];
    for (int i = 1; i < N - 1; i++) {
        res += abs(A[i]);
    }
    cout << res << endl;

    for (int i = N - 2; i > 0 && A[i] >= 0; i--) {
        cout << A[0] << " " << A[i] << endl;
        A[0] -= A[i];
    }
    for (int i = 1; i < N - 1 && A[i] < 0; i++) {
        cout << A[N - 1] << " " << A[i] << endl;
        A[N - 1] -= A[i];
    }

    cout << A[N - 1] << " " << A[0] << endl;
    return 0;
}