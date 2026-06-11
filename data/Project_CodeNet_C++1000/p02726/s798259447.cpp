#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 2e3 + 5, M = 2e5;
ll costs[M], ans[M];
vector<vector<pair<int, int>>> v;
int n, x, y;
void dijkestra(int src){
    priority_queue<pair <ll, ll>> pq;
    for(int i = 0; i < N; i++)
        costs[i] = 1e12;
    pq.push({0, src});
    costs[src] = 0;
    while(!pq.empty()){
        ll cost = -pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if (cost > costs[node]) continue;
        for(ll i = 0; i < v[node].size(); i++){
            if(cost + v[node][i].second < costs[v[node][i].first]){
                costs[v[node][i].first] = cost + v[node][i].second;
                pq.push({-(costs[v[node][i].first]), v[node][i].first});
            }
        }
    }
    for(int i = 1; i <= n; i++) ans[costs[i]]++;
}
int main()
{
    Hello
    cin >> n >> x >> y;
    v.resize(n + 5);
    v[x].push_back({y, 1});
    v[y].push_back({x, 1});
    for(int i = 1; i <= n; i++){
        v[i].push_back({i + 1, 1});
        v[i + 1].push_back({i, 1});
    }
    for(int i = 1; i <= n; i++) dijkestra(i);
    for(int i = 1; i <= n - 1; i++)
        cout << ans[i]/2 << endl;
    return 0;
}