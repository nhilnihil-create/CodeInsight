#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int h, n;
    cin >> h >> n;
    
    vector<int> dp(h+1,100000005);
    dp[0] = 0;
    
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        //0~hでi番目の魔法を使った場合で更新
        rep(j,h) {
            int j_n = min(j+a, h);
            dp[j_n] = min(dp[j_n], dp[j]+b);
        }
    }
    
    cout << dp[h] << endl;
    
    
    
    return 0;
}


