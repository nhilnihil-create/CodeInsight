#include <iostream>

int main(){
    int n, k;
    std::cin >> n >> k;

    int ans = n - (k - 1) - 1;
    if(1 == k){
        ans = 0;
    }

    std::cout << ans << std::endl;

    return 0;
}