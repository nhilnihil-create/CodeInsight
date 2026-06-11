#include <iostream>
#include <vector>

int main(){
    int n; 
    std::cin >> n;

    int ans = n / 2;
    if(0 == n % 2){
        ans -= 1;
    }
    
    std::cout << ans << std::endl;

    return 0;
}