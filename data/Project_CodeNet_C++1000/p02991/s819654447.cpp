#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 1e5 + 5;
int n, m, x, y, s, t, vis[3][N];
queue<pair<int,int>> q;
vector<int> g[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> x >> y;
        g[x].push_back(y);
    }    

    cin >> s >> t;
    q.push({s, 0});
    vis[0][s] = 1;

    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        if(u.first == t && u.second % 3 == 0) return cout << u.second / 3, 0;

        int d = u.second + 1;
        for(int v : g[u.first]) if(vis[d % 3][v] == 0) vis[d % 3][v]++, q.push({v, d});
    }
    cout << -1;
}