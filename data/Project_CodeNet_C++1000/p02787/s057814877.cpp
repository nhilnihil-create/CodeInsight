#include "bits/stdc++.h"

using namespace std;

const int MAX = 100000000;

// DP by recursive function ----

//int minEnergy(int h, const vector<int>& A, const vector<int>& B, vector<int>& memo) {
//    if (h <= 0) {
//        return 0;
//    }
//    if (memo[h] > 0) {
//        return memo[h];
//    }
//
//    int ret = MAX;
//    for (int i = 0; i < A.size(); ++i) {
//        int e_i = minEnergy(h - A[i], A, B, memo) + B[i];
//        ret = min(ret, e_i);
//    }
//    memo[h] = ret;
//    return ret;
//}
//
//void Main() {
//    int H, N;
//    cin >> H >> N;
//    vector<int> A(N, 0), B(N, 0);
//    for (int i = 0; i < N; ++i) {
//        cin >> A[i] >> B[i];
//    }
//
//    vector<int> memo(H + 1, -1);
//    int ans = minEnergy(H, A, B, memo);
//    cout << ans << endl;
//}

// DP by matrix ----

void Main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<int> minEnergy(H + 1, -1);
    minEnergy[0] = 0;
    for (int h = 1; h <= H; ++h) {
        int temp = MAX;
        for (int i = 0; i < N; ++i) {
            if (h <= A[i]) {
                temp = min(temp, B[i]);
            }
            else {
                temp = min(temp, minEnergy[h - A[i]] + B[i]);
            }
        }
        minEnergy[h] = temp;
    }

    cout << minEnergy.back() << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
