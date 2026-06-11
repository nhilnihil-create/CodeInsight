#include<iostream>
#include<vector>

int main(void){
    int n;
    int ans = 0;
    std::cin >> n;
    int cur;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }
    int tmp_cnt = 0;
    for(int i = 1; i < n; i++){
        if(h[i] <= h[i-1]){
            tmp_cnt++;
        }else{
            tmp_cnt = 0;
        }
        ans = std::max(ans, tmp_cnt);
    }
    std::cout << ans << std::endl;
    return 0;
}