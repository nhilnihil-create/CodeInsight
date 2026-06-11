#include<iostream>
#include<queue>
#include<vector>

const int INF = 1e9 + 7;
int distance[500005][3];

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> edge(n);
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
    }
    int s, t;
    std::cin >> s >> t;
    s--;
    t--;

    for(int i = 0; i < 500005; i++){
        for(int j = 0; j < 3; j++){
            distance[i][j] = INF;
        }
    }

    q.push(std::make_pair(s, 0));
    distance[s][0] = 0;
    while(!q.empty()){
        int now_n = q.front().first;
        int now_l = q.front().second;
        for(int next_n : edge[now_n]){
            int next_l = (now_l + 1) % 3;
            if(distance[next_n][next_l] != INF){
                continue;
            }
            distance[next_n][next_l] = distance[now_n][now_l] + 1;
            q.push(std::make_pair(next_n, next_l));
        }
        q.pop();
    }
    int ans = distance[t][0];
    if(ans == INF){
        ans = -1;
    }else{
        ans /= 3;
    }
    std::cout << ans << std::endl;
    return 0;
}