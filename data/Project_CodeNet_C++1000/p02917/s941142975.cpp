#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N;
    cin >> N;
    vector<int> B(N - 1);
    for(int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    vector<int> A(N, 1000000);
    for(int i = N - 2; i >= 0; i--) {
        A[i + 1] = min(A[i + 1], B[i]);
        A[i] = min(A[i], B[i]);
    }
    ans = accumulate(A.begin(), A.end(), 0);
    cout << ans << endl;
}