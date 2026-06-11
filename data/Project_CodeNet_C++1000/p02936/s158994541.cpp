#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

vector<vector<int>>g;
void dfs(int v,int p,vector<int>& a) {
    if(v != p)a[v] += a[p];
    for(int nv : g[v]) {
        if(nv == p) continue;
        dfs(nv,v,a);
    }
}
int main() {
    int n,q;
    cin >> n >> q;
    g.assign(n,vector<int>());
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> point(n);
    rep(i,q) {
        int p,x;
        cin >> p >> x;
        p--;
        point[p] += x;
    }
    dfs(0,0,point);
    rep(i,n) cout << point[i] << " ";
    cout << endl;
}