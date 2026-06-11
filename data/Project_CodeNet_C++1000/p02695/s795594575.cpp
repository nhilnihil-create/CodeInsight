#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N, M, Q;
int a[55], b[55], c[55], d[55];
int res = 0;
vector<int> v(10);

void dfs(int cur = 0, int last = 1) {
    if (cur == N) {
        int tmp = 0;
        rep(i,Q) if ( v[b[i]] - v[a[i]] == c[i] ) tmp += d[i];
        chmax(res, tmp);
        return;
    }
    for (int i = last; i <= M; ++i) {
        v[cur] = i;
        dfs(cur+1, i);
    }
}
int main() {
    cin >> N >> M >> Q;
    rep(i,Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
    dfs();
    cout << res << endl;
}
