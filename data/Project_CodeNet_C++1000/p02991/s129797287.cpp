#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> graph(n);
    for(i = 0;i < m;++i){
        ll u,v;
        cin >> u >> v;
        --u;    --v;
        graph.at(u).push_back(v);
    }
    ll s,t;
    cin >> s >> t;
    --s;    --t;
    queue<pair<ll,ll>> que;
    vector<vector<ll>> vdis(n,vector<ll>(3,-1));
    ll top = s;
    vdis.at(top).at(0) = 0;
    que.emplace(top,0);
    while(!que.empty()){
        auto x = que.front();
        que.pop();
        ll now = x.first;
        ll dist = x.second;
        for(i = 0;i < graph.at(now).size();++i){
            ll next = graph.at(now).at(i);
            if(vdis.at(next).at((dist+1)%3) == -1){
                vdis.at(next).at((dist+1)%3) = dist+1;
                que.emplace(next,dist+1);
            }
        }
    }
    if(vdis.at(t).at(0) != -1){
        cout << vdis.at(t).at(0)/3 << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}