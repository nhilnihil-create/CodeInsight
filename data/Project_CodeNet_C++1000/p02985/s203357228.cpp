#include<iostream>
#include<queue>
#include<vector>

const int MOD = 1e9 + 7;

int main(void){
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> edge(n);
    std::vector<int> used(n);
    std::queue<int> q;

    for(int i = 0; i < n-1; i++){
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    long long ans = k;
    used[0] = 1;
    int res_color = k - 1;
    for(int next : edge[0]){
        ans = ans * res_color % MOD;
        used[next] = 1;
        res_color--;
        q.push(next);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        res_color = k - 2;
        for(int next : edge[now]){
            if(used[next]) continue;
            ans = ans * res_color % MOD;
            used[next] = 1;
            res_color--;
            q.push(next);
        }
    }
    std::cout << ans << std::endl;

    return 0;
}