#include <iostream>
#include <vector>

int main(){
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<int> c(n);
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for(int i = 0; i < n; ++i){
        std::cin >> c[i];
        for(int j = 0; j < m; ++j){
            std::cin >> a[i][j];
        }
    }
    int ans = 1e9;
    for(int bit = 0; bit < (1 << n); ++bit){
        std::vector<int> now(m);
        int tmp = 0;
        for(int i = 0; i < n; ++i){
            if(bit & (1 << i)){
                for(int j = 0; j < m; ++j) now[j] += a[i][j];
                tmp += c[i];
            }
        }
        bool ok = true;
        for(int i = 0; i < m; ++i){
            if(now[i] < x) ok = false;
        }
        if(ok) ans = std::min(ans, tmp);
    }
    std::cout << (ans == 1e9 ? -1 : ans) << std::endl;
}