#include <iostream>

int main(void){
    int N, tmp=1;
    std::string ans = "Yes";
    std::cin >> N;

    for (int i=0; i<N; ++i){
        int h;
        std::cin >> h;
        if (tmp < h){
            tmp = h - 1;
        } else if (tmp > h){
            ans = "No";
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
