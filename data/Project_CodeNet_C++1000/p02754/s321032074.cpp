#include <iostream>
#include <cmath>

int main(void){
    long long N, A, B, quo, rem, ans=0;
    std::cin >> N >> A >> B;

    quo = N / (A + B);
    rem = N % (A + B);

    if (rem > A) rem = A;
    ans += quo * A + rem;

    std::cout << ans << std::endl;

    return 0;
}
