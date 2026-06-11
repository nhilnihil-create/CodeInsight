#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;


int n, m;
int to_id(int v, int mod) {
    return v * 3 + mod;  
}

vector<int> BFS(vector<vector<int>> Hen, int s) {
    int n = Hen.size();
    vector<int> dist(n, INF);
    queue<int> que;
    dist[s] = 0;
    que.push(s);
    while(que.size()) {
        auto cur = que.front(); que.pop();
        for(auto i : Hen[cur]) {
            if(dist[i] != INF)continue;
            dist[i] = dist[cur] + 1;
            que.push(i);
        }
    }
    return dist;
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> hen(n * 3);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--, b--;
        for(int j = 0; j < 3; j++) {
            hen[to_id(a, j)].push_back(to_id(b, (j + 1) % 3));
        }
    }
    int s, t; cin >> s >> t; s--, t--;
    cout << (BFS(hen, to_id(s, 0))[to_id(t, 0)] == INF ? -1 : BFS(hen, to_id(s, 0))[to_id(t, 0)] / 3) << endl;

}