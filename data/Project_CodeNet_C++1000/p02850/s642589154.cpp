#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
template<class T> void chmax(T& a, T b) { if(a < b) a = b; }

int main() {
    int n; cin >> n;
    V<V<P<int, int> > > g(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }

    // 最大次数から最大色数を特定
    int mc = 0;
    for(int i = 0; i < n; i++) chmax(mc, (int)g[i].size());

    V<int> ans(n - 1, -1); // 各辺の色を記録
    V<int> d(n, -1); // 訪問未訪問の管理
    queue<P<int, int>> que;
    que.push({0, -1});
    d[0] = 1;
    while(!que.empty()){
        auto p1 = que.front();
        que.pop();
        int v = p1.first; // 頂点
        int c = p1.second; // 色
        int color = 1;
        if(color == c) color++; // 親と被ったらスキップ
        for(auto p2 : g[v]){
            // 未訪問の場合
            if(d[p2.first] == -1){
                d[p2.first] = 1;
                que.push({p2.first, color});
                ans[p2.second] = color;
                color++;
                if(color == c) color++; // 親と被ったらスキップ
            }
        }
    }
    cout << mc << endl;
    for(int i = 0; i < n - 1; i++) cout << ans[i] << endl;

}
