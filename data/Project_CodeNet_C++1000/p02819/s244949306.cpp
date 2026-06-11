#include <iostream>
#include <cmath>

int main(void){
    int X, ans;
    std::cin >> X;

    for (int i=X; X<100004; ++i){
        int tmp =  sqrt(i);
        bool flg = false;
        for (int j=2; j<tmp; ++j){
            if (i % j == 0){
                flg = true;
                break;
            }
        }
        if (flg == false){
            ans = i;
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
