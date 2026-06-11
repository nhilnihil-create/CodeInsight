#include <iostream>
#include <vector>

int main(){
    int m1, d1, m2, d2;
    std::cin >> m1 >> d1 >> m2 >> d2;

    int ans = 0;
    if(m1 != m2){
        ans = 1;
    }

    std::cout << ans << std::endl;

    return 0;
}