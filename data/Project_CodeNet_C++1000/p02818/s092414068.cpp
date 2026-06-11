#include<iostream>
using namespace std;


int main(){
    long long A, B, K;
    std::cin >> A >> B >> K;

    if(K >= (A + B)){
        A = 0;
        B = 0;
    }else if(K >= A){
        B = B - (K - A);
        A = 0;
    }else{
        A = A - K;
    }

    std::cout << A << " " << B;
}