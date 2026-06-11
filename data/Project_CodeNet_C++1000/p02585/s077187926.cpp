#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL<<60;
int N;
long long K;
vector<int> P;
vector<long long> C;

long long solve() {
    long long res = -INF;

    // 順列を各サイクルに分解する
    vector<bool> used(N, false);
    vector<vector<long long>> ss;
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        int cur = i;
        vector<long long> s;
        while (!used[cur]) {
            used[cur] = true;
            s.push_back(C[cur]);
            cur = P[cur];
        }
        ss.push_back(s);
    }

    // 各サイクルごとに考える
    for (auto vec : ss) {
        long long M = vec.size();

        // サイクルを二週したものの累積和
        vector<long long> sum(M*2+1, 0);
        for (int i = 0; i < M*2; ++i) sum[i+1] = sum[i] + vec[i%M];

        // amari[r] := 連続する r 個の総和の最大値
        vector<long long> amari(M, -INF);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                chmax(amari[j], sum[i+j] - sum[i]);
            }
        }

        // 余りの長さで場合分け
        for (int r = 0; r < M; ++r) {
            if (r > K) continue;
            long long q = (K - r) / M;
            //if (r == 0 && q == 0) continue;

            if (sum[M] > 0) chmax(res, amari[r] + sum[M] * q);
            else if (r > 0) chmax(res, amari[r]);
        }
    }
    return res;
}

int main() {
    cin >> N >> K;
    P.resize(N); C.resize(N);
    for (int i = 0; i < N; ++i) cin >> P[i], --P[i];
    for (int i = 0; i < N; ++i) cin >> C[i];
    cout << solve() << endl;
}