#include<iostream>
#include<queue>
#include<vector>

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> job(m);
    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        if(a > m) continue;
        job[m-a].push_back(b);
    }
    std::priority_queue<int> q;
    int ans = 0;
    for(int i = m-1; i >= 0; --i){
        for(int j : job[i]){
            q.push(j);
        }
        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    std::cout << ans << std::endl;
    return 0;
}