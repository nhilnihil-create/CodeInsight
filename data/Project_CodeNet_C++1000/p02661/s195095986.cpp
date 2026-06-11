//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans;

    if (N % 2 == 0) {
        int ma = B[N/2-1] + B[N/2];
        int mi = A[N/2-1] + A[N/2];
        ans = ma - mi + 1;
    }
    else {
        int ma = B[(N+1)/2-1];
        int mi = A[(N+1)/2-1];
        ans = ma - mi + 1;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}