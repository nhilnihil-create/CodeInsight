#include<iostream>
#include<vector>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define INF  1000000000

int main(){
    int h,n; std::cin >> h >> n;
    std::vector<int> a(n), b(n);
    rep(i,n) std::cin >> a[i] >> b[i];

    std::vector<int> dp(h+1,INF); dp[0]=0;
    for(int i=1; i<=h; ++i){
        rep(j,n){
            int k=std::max(i-a[j],0);
            dp[i] = std::min(dp[i], dp[k]+b[j]);
        }
    }
    std::cout << dp[h] << std::endl;
    return 0;
}