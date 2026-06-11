#include <iostream>
#include <vector>

int main() {
    int N;
    long int ans = 0;
    std::cin >> N;
    std::vector<long int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A.at(i);
    }

    for(int i = 1; i < N; i++) {
        if(A.at(i - 1) > A.at(i)) {
            ans += A.at(i - 1) - A.at(i);
            A.at(i) = A.at(i - 1);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
