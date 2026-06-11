#include<iostream>
#include<string>

int main(){
        int K, X;
  		std::cin >> K >> X;
        if(500*K >= X) std::cout << "Yes";
        else std::cout << "No";
}