#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

long long ans;
long long N,M,Q;
vector<long long> a, b, c, d;

long long score(vector<long long>& A) {
    long long sc = 0;
    rep (i, Q) {
        if (A[b[i]-1] - A[a[i]-1] == c[i]) sc += d[i];
    }
    return sc;
}

void dfs(vector<long long>& A) {
    if (A.size() == N) {
        ans = max(ans, score(A));
        return;
    }
    for (int x = A.back(); x <= M; ++x) {
        A.push_back(x);
        dfs(A);
        A.pop_back();
    }
}

void solve() {
    ans = 0;
    vector<long long>A(1,1);
    dfs(A);
    cout << ans << endl;
}

int main() {
    scanf("%lld", &N);
    scanf("%lld", &M);
    scanf("%lld", &Q);
    a = std::vector<long long>(Q);
    b = std::vector<long long>(Q);
    c = std::vector<long long>(Q);
    d = std::vector<long long>(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
        scanf("%lld", &c[i]);
        scanf("%lld", &d[i]);
    }
    solve();
    return 0;
}
