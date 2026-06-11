#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll v,e;
    cin >> v >> e;
    vector<ll> invec(v, 0);
    vector<vector<ll>> graph(v);
    for(i = 0;i < e;++i){
        ll s,t;
        cin >> s >> t;
        graph.at(s).push_back(t);
        ++invec.at(t);
    }
    queue<ll> que;
    for(i = 0;i < v;++i){
        if(invec.at(i) == 0){
            que.push(i);
            --invec.at(i);
        }
    }
    vector<ll> ans;
    while(!que.empty()){
        ll top = que.front();
        que.pop();
        ans.push_back(top);
        for(auto next: graph.at(top)){
            if(--invec.at(next) == 0) que.push(next);
        }
    }
    for(i = 0;i < v;++i){
        cout << ans.at(i) << endl;
    }

    return 0;
}
