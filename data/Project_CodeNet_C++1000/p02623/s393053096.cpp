#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<long long> A(N), B(M);
    vector<long long> SA(N+1, 0), SB(M+1, 0); // 累積和
    for (int i = 0; i < N; ++i) cin >> A[i], SA[i+1] = SA[i] + A[i];
    for (int i = 0; i < M; ++i) cin >> B[i], SB[i+1] = SB[i] + B[i];

    int result = 0;
    for (int x = 0; x <= N; ++x) {
        if (SA[x] > K) break;

        int y = upper_bound(SB.begin(), SB.end(), K - SA[x]) - SB.begin();
        --y;
        result = max(result, x + y);
    }
    cout << result << endl;
}