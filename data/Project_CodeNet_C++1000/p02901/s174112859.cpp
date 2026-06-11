#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int n, m; scanf("%d %d", &n, &m);
    vector<int> cost(m);
    vector<vector<int> > key(m);
    for(int i = 0; i < m; i++){
        int num; scanf("%d %d", &cost[i], &num);
        for(int j = 0; j < num; j++){
            int x; scanf("%d", &x);
            key[i].push_back(x - 1);
        }
    }
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        for(int i = 0; i < m; i++){
            int num = bit;
            for(int j = 0; j < key[i].size(); j++) num = num | (1 << key[i][j]);
            dp[num] = min(dp[num], dp[bit] + cost[i]);
        }
    }
    int ans = dp[(1 << n) - 1];
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
}