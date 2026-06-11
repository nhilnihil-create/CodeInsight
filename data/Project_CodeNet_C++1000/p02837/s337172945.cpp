#include <iostream>
#include <vector>
int main(void){
    
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, bool>>> testimony(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        for (int j = 0; j < a; j++) {
            int num;
            int ToF;
            std::cin >> num >> ToF;
            if (ToF == 1) testimony[i].push_back({num, true});
            else testimony[i].push_back({num, false});
        }
    }
    
    int ans = 0;
    
    for (int bit = 0; bit < (1<<n); bit++) {
        int cnt = 0;
        std::vector<bool> check(n);
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) check[i] = true;
            else check[i] = false;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < testimony[i].size(); j++) {
                if (!check[i]) break;
                if (check[testimony[i][j].first-1] != testimony[i][j].second) flag = false;
            }
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                if (check[i]) cnt++;
            }
        }
        ans = std::max(ans, cnt);
    }
    
    std::cout << ans << std::endl;
    
}