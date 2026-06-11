#include<iostream>
using namespace std;

int main(){
    string S, T, U;
    int A, B;

    std::cin >> S >> T;
    std::cin >> A >> B;
    std::cin >> U;

    if(U == S){
        A = A - 1;
    }else{
        B = B - 1;
    }

    std::cout << A << " " << B;
}