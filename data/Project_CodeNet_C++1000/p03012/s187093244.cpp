#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for(int i = 0; i < n; i++){
        std::cin >> w[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += w[i];
    }
    int sum1 = 0;
    int sum2;
    int ans = 1e9;
    for(int i = 0; i < n-1; i++){
        sum1 += w[i];
        sum2 = sum - sum1;
        int diff = sum1 - sum2;
        if(diff < 0) diff = -diff;
        ans = std::min(ans, diff);
    }
    std::cout << ans << std::endl;
    return 0;
}