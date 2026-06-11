#include<iostream>
#include<vector>

const int INF = 1e9;

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> key;
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        int s = 0;
        for(int j = 0; j < b; j++){
            int c;
            std::cin >> c;
            c--;
            s |= 1 << c;
        }
        key.push_back(std::make_pair(a,s));
    }

    std::vector<int> dp(1<<n, INF);
    dp[0] = 0;
    for(int i = 0; i < 1<<n; i++){
        for(int j = 0; j < key.size(); j++){
            int s = i | key[j].second;
            dp[s] = std::min(dp[s], dp[i] + key[j].first);
        }
    }
    int ans = dp.back();
    if(ans == INF) ans = -1;
    std::cout << ans << std::endl;
    return 0;
}
