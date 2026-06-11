#include <iostream>
#include <vector>

int main(void){
    long long ans = 0;
    std::string S;
    std::cin >> S;
    int N = S.size();
    std::vector<long long> A(N + 1, 0);

    for (int i = 0; i < N; ++i){
        if (S.at(i) == '<'){
            A.at(i + 1) = A.at(i) + 1;
        }
    }
    for (int i = N - 1; i >= 0; --i){
        if (S.at(i) == '>'){
            if (A.at(i) <= A.at(i + 1)){
                A.at(i) = A.at(i + 1) + 1;
            }
        }
    }
    for (int i = 0; i <= N; ++i){
        ans += A.at(i);
    }

    std::cout << ans << std::endl;

    return 0;
}
