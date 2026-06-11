#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long
#define PI 3.14159265358979323846

using namespace std;
int main() {
    std::string s1 = "";
    std::string s2 = "";
    std::string S; std::cin >> S;
    intt TTT = 0;
    intt Q; std::cin >> Q;
    for (intt i = 0; i < Q; ++i) {
        intt t; std::cin >> t;
        if (t == 1) {
            std::swap(s1, s2);
            ++TTT;
        }
        else if (t == 2) {
            intt tt; std::cin >> tt;
            char c; std::cin >> c;
            if (tt == 1)
                s1 += c;
            else if (tt == 2)
                s2 += c;
        }
    }
    if (TTT % 2 == 1)
        std::reverse(S.begin(), S.end());
    std::reverse(s1.begin(), s1.end());
    std::cout << s1 + S + s2 << std::endl;

    return 0;
}