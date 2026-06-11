#include <iostream>
#include <string>

int main() {

    int N; // the length of a string S
    std::cin >> N;

    std::string S; // the string
    std::cin >> S;

    if (N % 2 == 1) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::string former = S.substr(0, N/2);
    std::string latter = S.substr(N/2, N/2);

    std::cout << (former.compare(latter) == 0 ? "Yes" : "No") << std::endl;

    return 0;

}
