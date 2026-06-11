#include <iostream>
#include <vector>

int main(void){
    int N;
    std::string ans = "No";
    std::vector<int> A(9);
    std::vector<int> num(101, 1);
    std::vector<std::vector<int>> C = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    };

    for (int i=0; i<9; ++i){
        std::cin >> A.at(i);
    }

    std::cin >> N;
    for (int i=0; i<N; ++i){
        int b;
        std::cin >> b;
        --num.at(b);
    }

    for (std::vector<int> c: C){
        if (num.at(A.at(c.at(0))) == 0 && num.at(A.at(c.at(1))) == 0 && num.at(A.at(c.at(2))) == 0){
            ans = "Yes";
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}