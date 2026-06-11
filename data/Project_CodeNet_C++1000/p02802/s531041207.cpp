#include <iostream>
#include <vector>

int main(void){
    int N, M, ans_n=0, ans_p=0;
    std::cin >> N >> M;
    std::vector<std::vector<int>> A(N, std::vector<int>(2, 0));

    for (int i=0; i<M; ++i){
        int p;
        std::string s;
        std::cin >> p >> s;
        if (s == "AC"){
            A.at(p - 1).at(1) = 1;
        } else if (A.at(p - 1).at(1) == 0){
            ++A.at(p - 1).at(0);
        }
    }

    for (std::vector<int> x: A){
        if (x.at(1) == 1){
            ++ans_n;
            ans_p += x.at(0);
        }
    }

    std::cout << ans_n << " " << ans_p << std::endl;

    return 0;
}
