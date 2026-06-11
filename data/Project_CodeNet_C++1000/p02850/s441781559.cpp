#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

vector<vector<P>> to(100000);
vector<int> c(100000, 0);
vector<bool> vis(100000, false);

void dfs(int v, int p){
    int cnt = 1;
    vis[v] = true;
    for(P t : to[v]){
        if(vis[t.first])continue;
        if(cnt == p)cnt++;
        dfs(t.first, cnt);
        c[t.second] = cnt;
        cnt++;
    }
}

int main() {
    int n;
    cin >> n;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(make_pair(b, i));
        to[b].push_back(make_pair(a, i));
    }
    int k = 0;
    rep(i, n)k = max(k, (int)to[i].size());
    dfs(0, 0);
    cout << k << endl;
    rep(i, n - 1)cout << c[i] << endl;

}