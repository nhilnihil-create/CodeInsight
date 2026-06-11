#include <bits/stdc++.h>
using namespace std;
using Int = long long;
void recur(vector<vector<int>> &A, const vector<int> &B, int level)
{
    if (B.size() <= 1) return;
    vector<int> C, D;
    for (int i = 0; i < B.size(); i++) {
        (i % 2 == 0 ? C : D).push_back(B[i]);
    }
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < D.size(); j++) {
            int s = C[i], t = D[j];
            A[min(s, t)][max(s, t)] = level;
        }
    }
    recur(A, C, level + 1);
    recur(A, D, level + 1);
}
int main() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<int> B(N);
    iota(begin(B), end(B), 0);
    recur(A, B, 1);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
