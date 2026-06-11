#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n-1);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        --a[i];
    }
    for(int i = 0; i < n; i++){
        std::cin >> b[i];
    }
    for(int i = 0; i < n - 1; i++){
        std::cin >> c[i];
    }

    int bi = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += b[a[i]];
        if(a[i] - bi == 1) ans += c[bi];
        bi = a[i];
    }
    std::cout << ans << std::endl;
    return 0;
}