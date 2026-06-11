#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int n;
vector<vector<pair<int,int>>> G;
vector<int> color;

void dfs(int now, int pre, int pre_color){
    int now_color = 1;
    for(auto next : G[now]){
        if(pre == next.first) continue;
        if(now_color == pre_color) now_color++;
        color[next.second] = now_color;
        dfs(next.first,now,now_color);
        now_color++;
    }
}

int main()
{
    cin >> n;
    G.resize(n);
    color.resize(n-1);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    int k = 0;
    rep(i,n){
        k = max(k,(int)G[i].size());
    }
    cout << k << endl;
    dfs(0,-1,-1);
    rep(i,n-1) cout << color[i] << endl;
}