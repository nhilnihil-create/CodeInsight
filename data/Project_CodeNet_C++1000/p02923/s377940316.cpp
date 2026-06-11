#include <iostream>

int main(void){
    int N, tmp_h, tmp=0, ans=0;
    std::cin >> N >> tmp_h;

    for(int i=1; i<N; ++i){
        int h;
        std::cin >> h;
        if (h <= tmp_h){
            ++tmp;
            tmp_h = h;
        } else {
            if (tmp > ans) ans = tmp;
            tmp = 0;
            tmp_h = h;
        }
    }

    if (tmp > ans) ans = tmp;

    std::cout << ans << std::endl;

    return 0;
}
