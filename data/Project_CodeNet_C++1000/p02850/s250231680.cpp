#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

map<P,int> mp;
vector<vector<int>> edge(1000000);

void dfs(int x,int p,int color){
    int sz = edge[x].size();
    int nu = 1;
    rep(i,sz){
        int nx = edge[x][i];
        if(nx == p) continue;
        mp[P(x,nx)] = nu;
        if(color == nu) {
            mp[P(x,nx)]++;
            nu++;
        }
        int col = mp[P(x,nx)];
        dfs(nx,x,col);
        nu++;
    }
}

int main(){
    int n; cin >> n;
    vector<P> E;
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        E.push_back(P(a,b));
    }
    int num = 0;
    rep(i,n){
        int x = edge[i].size();
        num = max(num,x);
    }
    cout << num << endl;
    mp[E[0]] = 1;
    int a = E[0].first,b = E[0].second;
    dfs(a,b,1);
    dfs(b,a,1);
    rep(i,n-1){
        int aa = E[i].first,bb = E[i].second;
        cout << mp[P(aa,bb)]+mp[P(bb,aa)] << endl;
    }
}