#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll n;
map<pair<ll,ll>,vector<pair<ll,ll>>> mp;
map<pair<ll,ll>,ll> vdist;
map<pair<ll,ll>,ll> seen;

ll dfs(ll pi, ll pj)
{
    if(seen[make_pair(pi,pj)] == 2) return vdist[make_pair(pi,pj)];
    ll dist = vdist[make_pair(pi,pj)];
    seen[make_pair(pi,pj)] = 1;
    if(!mp.count(make_pair(pi,pj))){
        seen[make_pair(pi,pj)] = 2;
        return 0;
    }
    ll tmp = 0;
    for(auto x:mp[make_pair(pi,pj)]){
        ll ni = x.first;
        ll nj = x.second;
        if(seen[make_pair(ni,nj)] == 1){
            cout << -1 << endl;
            exit(0);
        }
        tmp = max(tmp,dfs(ni,nj) + 1);
    }
    seen[make_pair(pi,pj)] = 2;
    return vdist[make_pair(pi,pj)] = tmp;
}

int main()
{
    ll i,j;
    cin >> n;
    for(i = 0;i < n;++i){
        ll pi = 0, pj = 0;
        rep(j,n-1){
            ll k;
            cin >> k;
            --k;
            ll ni = min(i,k);
            ll nj = max(i,k);
            mp[make_pair(pi,pj)].emplace_back(ni,nj);
            pi = ni;    pj = nj;
        }
    }
    vdist[make_pair(0,0)] = 0;
    cout << dfs(0,0) << endl;
    return 0;
}
