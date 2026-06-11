#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n,m,s,t;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
    }
    cin >> s >> t;
    --s; --t;

    queue<pair<int,int>> que;    
    vector<vector<bool>> seen(n,vector<bool>(3,false));

    que.push({s,0});
    seen[s][0] = true;

    while(!que.empty()) {
        int cv = que.front().first;
        int cd = que.front().second;
        que.pop();
        if(cv == t && cd%3 == 0) {
            cout << cd/3 << endl;
            return 0;
        }
                
        for(auto nv:g[cv]) {
            if(seen[nv][(cd+1)%3]) continue;
            que.push({nv,cd+1});
            seen[nv][(cd+1)%3] = true;
        }
    }

    cout << -1 << endl;
    return 0;
}