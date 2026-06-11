#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, K = 0;
int a[100010], b[100010];
vector<int> adj[100010];
map<pint, int> color;
bool visited[100010];

void dfs(int index, int c){
    if(visited[index]){
        return;
    }
    visited[index] = true;
    int d = 1;
    for(int next : adj[index]){
        if(visited[next]) continue;
        if(d == c) d++;
        color[pint(index, next)] = color[pint(next, index)] = d;
        dfs(next, d);
        d++;
    }
}

signed main(){
    cin >> N;
    REP(i, N - 1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    dfs(0, 0);
    for(auto p : color) K = max(K, p.second);
    PRINT(K);
    REP(i, N - 1) PRINT(color[pint(a[i], b[i])]);
    return 0;
}