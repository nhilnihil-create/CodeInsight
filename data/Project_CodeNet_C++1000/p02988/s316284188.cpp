#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for(int i = 0; i < n; i++){
        std::cin >> p[i];
    }
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        int cnt = 0;
        if(p[i] < p[i+1]) cnt++;
        if(p[i] < p[i-1]) cnt++;
        if(cnt == 1) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}