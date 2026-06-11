#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


vector<int> edge;
vector<vector<pair<int, int>>> g;


void dfs(int v, int p=-1, int pc=-1){
    int color=1;
    if(color==pc) color += 1;
    for(auto x: g[v]){
        if(x.first==p) continue;
        edge[x.second] = color;
        dfs(x.first, v, color);
        color += 1;
        if(color==pc) color += 1;
    }
}


int main(){
    int n;  cin >> n;
    g.resize(n);
    edge.assign(n-1, -1);

    REP(i, n-1){
        int a, b;   cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    int max_color=0;
    REP(i, n)   max_color = max(max_color, (int)g[i].size());
    dfs(0);
    cout << max_color << endl;
    for(auto x: edge)
        cout << x << endl;
}