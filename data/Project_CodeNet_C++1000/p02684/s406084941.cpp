#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int solve(const vector<int> &A, long long K) {
    deque<int> a; // 繰り返しの部分
    vector<bool> seen(A.size(), false); // 一度見たかどうか
    int cur = 0;
    while (true) {
        // 一度通った頂点を見つけたときの処理
        if (seen[cur]) {
            while (a[0] != cur) {
                // 最初の余計な数手分を除去する
                --K;
                a.pop_front();

                // 繰り返す前に K が限界になったらリターン
                if (K == 0) return a[0] + 1;
            }
            break;
        }
        // 最初は愚直にシミュレーションしつつ、履歴をメモしていく
        a.push_back(cur);
        seen[cur] = true;
        cur = A[cur];
    }
    return a[K % a.size()] + 1;
}

int main() {
    long long N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i], --A[i];
    cout << solve(A, K) << endl;
}