#include<iostream>
#include<string>

int main(){
        int A,B,C;
        std::cin >> A;
        std::cin >> B;
        std::cin >> C;
        if(A == B && B != C || A == C && A != B || B == C && C != A)
          std::cout << "Yes";
        else
          std::cout << "No";

}