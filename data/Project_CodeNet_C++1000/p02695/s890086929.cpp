
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

void Main() {
    // input
    int N, M, Q;
    cin >> N >> M >> Q;
    int a[Q+1], b[Q+1], c[Q+1], d[Q+1];
    for (int i = 1; i <= Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }



    // translate    
    // 数列 A_1, …, A_N の総当り
    vector<int> vec(M+N-1, 1); // 0 を ○, 1 を棒として, 各1の左にある0の数を数える
    for (int i = 0; i < M - 1; i++) {
        vec[i] = 0;
    }


    u_int64_t ans = 0;
    do {
        // 数列A 列挙部
        int zero_count = 0;
        vector<int> A(1); // 数列A
        for (int i = 0; i < N+M-1; i++) {
            if (vec[i] == 0) {
                zero_count++;
            } else {
                A.push_back(zero_count);
            }
        }
        u_int64_t score = 0;
        // d_i の計算
        for (int i = 1; i <= Q; i++) {
            if (A[b[i]] - A[a[i]] == c[i]) {
                score += d[i];
            }
        }
        ans = max(ans, score);
    } while (next_permutation(vec.begin(), vec.end()));


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
