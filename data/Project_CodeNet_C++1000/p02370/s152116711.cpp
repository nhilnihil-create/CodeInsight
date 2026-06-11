#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>());
    vector<int> deg(v);
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        deg[b]++;
    }
    vector<int> topological;
    queue<int> q;
    for(int i = 0; i < v; i++) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int s = q.front();
        topological.push_back(s);
        q.pop();
        for(auto to: graph[s]){
            deg[to]--;
            if(!deg[to]) q.push(to);
        }
    }
    for(int i = 0; i < v; i++) cout << topological[i] << "\n";
}
