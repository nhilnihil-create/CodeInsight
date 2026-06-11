#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M, Q;
vector<int> A, B, C, D;
int ans;

void dfs(vector<int> X) {
    if (sz(X) == N+1) {
        int temp = 0;
        rep(i, Q) {
            if (X[B[i]] - X[A[i]] == C[i]) temp += D[i];
        }
        ans = max(ans, temp);
        return;
    }
    X.push_back(X.back());
    while (X.back() <= M) {
        dfs(X);
        X.back()++;
    }
}

int main() {
    cin >> N >> M >> Q;
    A = B = C = D = vector<int> (Q);
    rep(i, Q) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    dfs(vector<int> (1, 1));
    cout << ans << '\n';
    return 0;
}