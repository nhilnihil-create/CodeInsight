#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    map<pair<int,int>,int> en;
    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        if(a>b) swap(a,b);
        --a;
        --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        en[make_pair(a,b)]=i;
    }
    int sn=0;
    for(int i = 1; i < n; i++) {
        if(g[i].size()>g[sn].size()) sn=i;
    }
    int ct=g[sn].size();
    int ans[n-1];
    vector<int> color(n,-1);
    queue<int> que;
    que.push(sn);
    color[sn]=0;
    while(!que.empty()) {
        int v=que.front();
        que.pop();
        int pc=1;
        for (int nv : g[v]) {
            if (color[nv] != -1) continue;

            if(color[v]==pc) pc++;
            color[nv]=pc;
            pc++;
            que.push(nv);

            int tv=v;
            int tnv=nv;
            if(tv>tnv) swap(tv,tnv);
            int ten=en[make_pair(tv,tnv)];
            ans[ten]=color[nv];
        }
    }

    cout << ct << "\n";
    for(int i = 0; i < n-1; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}