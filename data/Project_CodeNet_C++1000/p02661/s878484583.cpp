#include <bits/stdc++.h>


using namespace std;


int main(void) {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    if (N % 2 == 1) {
        int l, r;
        l = A[N / 2];
        r = B[N / 2];
        ans += r - l + 1;
    } else {
        int l, r;
        l = A[N / 2] + A[N / 2 - 1];
        r = B[N / 2] + B[N / 2 - 1];
        ans += r - l + 1;
    }
    cout << ans << endl;
}
