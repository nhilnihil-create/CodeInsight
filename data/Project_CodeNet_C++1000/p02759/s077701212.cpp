#include<iostream>

int main(){
        int N;
        std::cin >> N;
        if(N%2 == 1) N += 1;
        std::cout << N/2;
}