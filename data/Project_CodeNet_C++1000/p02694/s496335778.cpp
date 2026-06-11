#include<iostream>

int main(){
    long long unsigned int A = 100;
    long long unsigned int X;
    long long unsigned int year=0;
    std::cin >> X;
    while(1){
        if(X <= A) break;
        A += A/100;
        year++;
    }
    std::cout << year << "\n";
    return 0;
}