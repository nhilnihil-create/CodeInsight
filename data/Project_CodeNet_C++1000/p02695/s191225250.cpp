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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<int>vec(N+M-1, 1);
    for (int i = 0; i < M-1; ++i) vec[i] = 0;
    int ans = 0;
    do {
        int zero_cnt = 0;
        int score = 0;
        vector<int> A;
        for (int i = 0; i < N+M-1; ++i) {
            if (vec[i] == 0) zero_cnt++;
            else A.push_back(zero_cnt + 1);
        } 
        for (int i = 0; i < Q; ++i) {
            if (A[b[i]] - A[a[i]] == c[i]) score += d[i];
        }
        ans = max(ans, score);
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans << endl;
    return 0;
}