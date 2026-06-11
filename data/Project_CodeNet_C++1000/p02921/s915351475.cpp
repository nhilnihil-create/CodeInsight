#include<iostream>
#include<string>
int main() {
        std::string S,T;
        std::cin >> S >> T;
        std::cout << int(S[0] == T[0]) + int(S[1] == T[1]) + int(S[2] == T[2]); 
}