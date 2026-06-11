#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    map<P,int> g;
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[make_pair(a,b)] = g[make_pair(b,a)] = i;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int k = 0;
    rep(i,n) k = max(k, (int)tree[i].size());

    vector<int> c(n-1, -1);

    queue<P> que;
    int col = 1;
    for(auto p : tree[0]){
        que.push(make_pair(0,p));
        c[g[make_pair(0,p)]] = col;
        col++;
    }

    //int s = 1;
    while(!que.empty()){
        P pos = que.front();
        int now = pos.second, pred = pos.first;
        int pred_col = c[g[pos]];
        col = 1;
        que.pop();
    //    if(s <= 10)cout << pos.first << ' ' << pos.second << endl;
    //    s++;
        for(auto p : tree[now]){
            if(p == pred) continue;
            if(col == pred_col) col++;
            que.push(make_pair(now, p));
            c[g[make_pair(now, p)]] = col;
            col++;
        }
    }
    cout << k << endl;
    rep(i,n-1) cout << c[i] << endl;
}