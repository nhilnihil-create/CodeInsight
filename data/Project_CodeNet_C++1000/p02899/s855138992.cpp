#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> A(N, std::vector<int>(2));
    for (int i=0; i<N; ++i){
        std::cin >> A.at(i).at(0);
        A.at(i).at(1) = i + 1;
    }

    std::sort(A.begin(), A.end());

    for (int i=0; i<N-1; ++i) {
        std::cout << A.at(i).at(1) << " ";
    }
    std::cout << A.at(N - 1).at(1) << std::endl;

    return 0;
}
