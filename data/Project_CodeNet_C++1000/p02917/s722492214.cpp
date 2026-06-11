#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> b(n-1);
    for(int i = 0; i < n-1; i++){
        std::cin >> b[i];
    }
    int ans = 0;
    ans += b[0];
    for(int i = 0; i < n-2; i++){
        ans += std::min(b[i], b[i+1]);
    }
    ans += b[n-2];
    std::cout << ans << std::endl;
    return 0;
}