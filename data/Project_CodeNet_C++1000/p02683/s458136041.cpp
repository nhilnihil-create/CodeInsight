#include <iostream>
#include <vector>
int main(void){
    
    int n, m, x;
    std::cin >> n >> m >> x;
    
    std::vector<int> c(n);
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int bit = 0; bit < (1<<n); bit++) {
        int sum = 0;
        std::vector<int> a_check(m, 0);
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) {
                sum += c[i];
                for (int k = 0; k < m; k++) {
                    a_check[k] += a[i][k];
                }
            }
        }
        bool flag = true;
        for (int k = 0; k < m; k++) {
            if (a_check[k] < x) {
                flag = false;
                break;
            }
        }
        if (flag) ans = ans == -1 ? sum : std::min(ans, sum);
    }
    
    std::cout << ans << std::endl;
    
}