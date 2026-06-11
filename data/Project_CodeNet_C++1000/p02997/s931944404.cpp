// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;

    int mx = (N-1)*(N-2)/2;  // max
    if (mx < K) {
        puts("-1");
        return 0;
    }

    // 辺（u, v）をpairで表現する。
    vector<P> ans;

    // 頂点Nを真ん中にしてスター（うに）を作る。
    rep(i, N-1) {
        ans.push_back(P(i+1, N));
    }
    int add = mx-K;  // これだけ追加したい。
    
    // 辺の候補を列挙する。
    vector<P> edge;
    rep(i, N-1) rep(j, i) edge.push_back(P(i+1, j+1));
    
    // 必要な数だけansにへんを突っ込む。
    rep(i, add) ans.push_back(edge[i]);
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}