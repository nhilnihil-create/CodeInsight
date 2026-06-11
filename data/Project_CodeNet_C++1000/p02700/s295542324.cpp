#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int count_takahasi = C / B;
    if(C % B != 0) {
        count_takahasi++;
    }

    int count_aoki = A / D;
    if(A % D != 0) {
        count_aoki++;
    }

    if(count_takahasi <= count_aoki) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}