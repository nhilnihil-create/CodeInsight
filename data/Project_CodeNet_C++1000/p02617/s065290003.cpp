#include <fstream>
#include <vector>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define ll long long
#define pii pair<int,int>
#define add(a,b) ((int) (((ll) (a) + (b))%MOD))
#define mul(a,b) ((int) (((ll) (a) * (b))%MOD))
#define PB emplace_back
#define MP make_pair
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N,a,b;
ll edges = 0;
vector<int> graph [200000];

void dfs(int node, int par) {
    for (int ne: graph[node]) {
        if (ne == par) continue;
        edges += (ll) (min(node,ne)+1) * (ll) (N-max(node,ne));
        dfs(ne, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    F0R(i,N-1) {
        cin >> a >> b;
        a--; b--;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    dfs(0,-1);
    ll sum = 0;
    F0R(i,N) sum += (ll) (N-i) * (ll) (i+1);
    cout << sum-edges << '\n';
}