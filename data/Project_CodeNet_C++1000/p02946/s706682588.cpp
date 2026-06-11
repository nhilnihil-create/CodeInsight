#include<iostream>
#include<cmath>
using namespace std;



int main(){
    int X, K;
    std::cin >> K >> X;

    int start = X - (K - 1);
    int end = X + (K + 1);

    for(int i = 0 ; i < 2*K - 1; i++){
        std::cout << start + i << " ";
    }
}
