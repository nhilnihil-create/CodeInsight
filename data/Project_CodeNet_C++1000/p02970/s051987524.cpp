#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double N, D, n;
    std::cin >> N >> D;

    n = ceil(N/(2.0 * D + 1.0));

    std::cout << (int)round(n);

}