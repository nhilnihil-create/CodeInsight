#include <iostream>

int main(void){
    int A, B, ans=-1;
    std::cin >> A >> B;

    for (int i=0; i<10001; ++i){
        if (i * 8 / 100 == A && i / 10 == B){
            ans = i;
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
