#define loop(i, s, e) for(ll i = s;i < e;i++)

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long signed ll;

ll v, e, s, t;
vector<pair<ll, ll>> w;
bool color[10000];
ll indeg[10000];
queue<ll> q;
vector<ll> out;

void bfs(ll ss){
    q.push(ss);
    color[ss] = true;
    while(!q.empty()){
        int u = q.front();q.pop();
        out.push_back(u);
        auto l = lower_bound(w.begin(),w.end(),make_pair((ll)u,(ll)0));
        auto r = lower_bound(w.begin(),w.end(),make_pair((ll)u+1,(ll)0));
        for(auto itr = l;itr != r;itr++){
            indeg[itr->second]--;
            if(!indeg[itr->second] && !color[itr->second]){
                color[itr->second] = true;
                q.push(itr->second);
            }
        }

    }
}

int main() {
    cin >> v >> e;
    loop(i, 0, e) {
        cin >> s >> t;
        indeg[t]++;
        w.push_back(make_pair(s, t));
    }
    sort(w.begin(), w.end());
    loop(u,0,v) if(!indeg[u] && !color[u]) bfs(u);
    for(auto x:out) cout << x << endl;
}


