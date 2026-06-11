#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, maxs=0, maxi=0;
vector<ll> A(MAXN, 0), ans(MAXN, 0);
vector<vector<pair<ll, ll>>> G;

void bfs() {
    queue<pair<ll, ll>> Q;
    vector<ll> color(N, 0);
    color[maxi]=1;
    for(int i=0;i<G[maxi].size();i++) {
        Q.push(make_pair(G[maxi][i].first, i));
        color[G[maxi][i].first]=1;
        ans[G[maxi][i].second] = i;
    }
    while(!Q.empty()) {
        pair<ll, ll> p = Q.front();
        Q.pop();
        int c=0;
        for(int i=0;i<G[p.first].size();i++) {
            if(color[G[p.first][i].first]==0) {
                if(c==p.second) c++;
                Q.push(make_pair(G[p.first][i].first, c));
                color[G[p.first][i].first]=1;
                ans[G[p.first][i].second] = c;
                c++;
            }
        }
    }
}

signed main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++) {
        ll s, g;
        cin >> s >> g;
        s--;
        g--;
        G[s].push_back(make_pair(g, i));
        G[g].push_back(make_pair(s, i));
    }
    for(int i=0;i<N;i++) {
        if(maxs<G[i].size()) {
            maxs = G[i].size();
            maxi = i;
        }
    }
    bfs();
    cout << maxs << endl;
    for(int i=0;i<N-1;i++) {
        cout << ans[i]+1 << endl;
    }
    return 0;
}