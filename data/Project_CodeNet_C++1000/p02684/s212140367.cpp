#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
    }
    int logK = 1;
    while((1LL << logK) < K) ++logK;
    vector<vector<int>> doubling(logK, vector<int>(N));
    for (int i = 0; i < N; ++i) doubling[0][i] = A[i];
    
    for (int i = 0; i < logK - 1; ++i) {
        for (int j = 0; j < N; ++j) {
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
        }
    }
    int now = 0;
    for (int k = 0; K > 0; ++k) {
        if (K & 1) now = doubling[k][now];
        K = K >> 1;
    }
    cout << now +  1 << endl;
    return 0;
}