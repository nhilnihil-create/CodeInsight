#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    int A, B, K;
    std::cin >> K >> A >> B;

    bool flag = false;
    for(int i=A; i <= B; i++) {
        if(i % K == 0) {
            std::cout << "OK" << std::endl;
            flag = true;
            break;
        }
    }
    if(flag == false) {
        std::cout << "NG" << std::endl;
    }

}