#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

ll N, M, V, P;
vector<ll> A, S;

bool check(int x) {
    int X = upper_bound(A.begin(), A.end(), A[x]) - A.begin() - 1;
    if (X + P >= V) {
        return (A[X] + M) >= A[N - P];
    }
    int l = X + 1, r = N - P;
    ll gain = A[X] + M;
    // 配らなければいけない残スコア
    ll rest = M * (V - X - P); // x以下の問題と上位P-1個にはM個配って良い,x自身にもM個配っているので,それらを除いた個数*M
    ll pool = 0;
    for (int i = l; i <= r; i++) {
        if (A[i] > gain) return false;
        pool += min(M, gain - A[i]);
    }
    return (rest <= pool);
}

int main() {
    cin >> N >> M >> V >> P;
    A.resize(N);
    S.resize(N + 1);
    rep(i, N)cin >> A[i];
    sort(A.begin(), A.end());
    rep(i, N)S[i + 1] = S[i] + A[i];

    int ok = N - 1, ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << N - ok << endl;
    return 0;
}