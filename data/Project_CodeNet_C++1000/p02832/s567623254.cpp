#include <iostream>

int main(void){
    int N, ans=-1, tmp=1;
    bool flg = false;
    std::cin >> N;

    for (int i=0; i<N; ++i){
        int a;
        std::cin >> a;
        if (a == tmp){
            ++tmp;
            flg = true;
        }
    }

    if (flg){
        ans = N - tmp + 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
