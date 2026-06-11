#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> A(N), B(M);
    ll A_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A_sum += A[i];
    }
    for (int i = 0; i < M; i++) cin >> B[i];

    int num = 0, su = 0; ll B_sum = 0;
    for (int i = N; i >= 0; i--) {
        for (int j = num; j <= M; j++) {
            num = j;
            if (A_sum + B_sum > K) break;
            su = max(su, i + j);
            if (j == M) break;
            B_sum += B[j];
        }
        if (i == 0) break;
        A_sum -= A[i-1];
    }
    cout << su << endl;
}