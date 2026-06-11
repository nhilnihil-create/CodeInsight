#include <iostream>

int main(){
    int N; std::cin >> N;
    bool flag = false;
    for (int i{ 0 }; i < N; ++i) {
        int a; std::cin >> a;
        if (a % 2 == 0) {
            if (a % 3 != 0 && a % 5 != 0)
                flag = true;
        }
    }
    if (flag == true) std::cout << "DENIED" << std::endl;
    else std::cout << "APPROVED" << std::endl;

    return 0;
}
