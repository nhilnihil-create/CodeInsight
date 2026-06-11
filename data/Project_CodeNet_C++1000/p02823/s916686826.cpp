#include <iostream>
#include <algorithm>

int main(void){
    long long N, A, B, ans;
    std::cin >> N >> A >> B;

    if ((B - A) % 2 == 0){
        ans = (B - A) / 2;
    } else {
        ans = std::min(A - 1, N - B) + 1 + (B - A - 1) / 2;
    }
    
    std::cout << ans << std::endl;

    return 0;
}
