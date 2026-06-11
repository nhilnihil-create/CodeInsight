#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<int>> Hen(n);
    vector<vector<int>> dist(n, vector<int>(3, -3));

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        Hen[a].push_back(b);
    }cin >> s >> t; s--; t--;

    queue<pair<int,int>> que;
    vector<vector<bool>> seen(n,vector<bool>(3));
    que.push({s, 0}); //sでmod3で0;

    while(que.size())
    {
        auto cur = que.front();
        que.pop();
        for(auto i : Hen[cur.first]){
            if(seen[i][(cur.second + 1) % 3])continue;
            dist[i][(cur.second + 1) % 3] = cur.second + 1;
            seen[i][(cur.second + 1) % 3] = true;
            que.push({i, cur.second + 1});
        }
    }
    cout << dist[t][0] / 3<< endl;

}