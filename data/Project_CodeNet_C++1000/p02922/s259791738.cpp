#include <bits/stdc++.h>

int main(){
    int A, B;
    std::cin >> A >> B;

    int r = ((B - 1) % (A - 1) > 0)? 1 : 0;
    int nums = (B - 1) / (A - 1) + r;

    std::cout << nums << std::endl;
}