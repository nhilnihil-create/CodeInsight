#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 2e5 + 5;
vector<vector<int>>v;
int par[N];
void bfs(){
    queue<pair<int, ll>>q;
    bool vis[N] = {};
    q.push({1, par[1]});
    vis[1] = true;
    while(q.size()){
        int numb = q.front().first;
        ll cost = q.front().second;
        q.pop();
        for(int i = 0; i < v[numb].size(); i++){
            if(vis[v[numb][i]]) continue;
            vis[v[numb][i]] = true;
            par[v[numb][i]] += cost;
            q.push({v[numb][i], par[v[numb][i]]});
        }
    }
}
int main()
{
    Hello
    int n, q;
    cin >> n >> q;
    v.resize(n + 5);
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0, p, x; i < q; i++){
        cin >> p >> x;
        par[p] += x;
    }
    bfs();
    for(int i = 1; i <= n; i++) cout << par[i] << " ";
    return 0;
}
