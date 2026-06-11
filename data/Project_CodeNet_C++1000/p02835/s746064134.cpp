#include<iostream>

int main(){
        int A[3];
        std::cin >> A[0] >> A[1] >> A[2];
        if(A[0] + A[1] + A[2] >= 22) std::cout << "bust";
        else std::cout<<"win";
}