#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
vector<map<int, int>> graph;
int main(){
    int n;
    cin >> n;
    graph.resize(n);
    vector<pair<int, int>> edges_in_order;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        edges_in_order.emplace_back(a - 1, b - 1);
        graph[a - 1][b - 1] = -1;
        graph[b - 1][a - 1] = -1;
    }
    int mx = 0;
    vector<vector<bool>> color;
    for(int i = 0; i < n; i++){
        color.push_back(vector<bool>(graph[i].size()));
        mx = max(mx, (int)graph[i].size());
    }
    for(int i = 0; i < n; i++){
        int least = 0;
        for(auto itr : graph[i]){
            if(itr.second != -1) continue;
            for(int j = least; j < color[i].size(); j++){
                if(color[i][j]) continue;
                least = j + 1;
                color[i][j] = true;
                graph[i][itr.first] = j;
                graph[itr.first][i] = j;
                if(j < graph[itr.first].size()) color[itr.first][j] = true;
                break;
            }
        }
    }
    cout << mx << "\n";
    for(auto itr : edges_in_order){
        cout << graph[itr.first][itr.second] + 1 << "\n";
    }
    /*for(int i = 0; i < n; i++){
        for(auto itr : graph[i]){
            cout << i + 1 << " " << itr.first + 1 << " " << itr.second + 1 << "\n";
        }
    }*/
}