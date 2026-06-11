#include<iostream>
#include<string>

int main(void){
        std::string S, T;
        std::cin >> S >> T;
        int counter = 0;
        for(int i = 0; i < S.length(); i++)
                if(S[i] != T[i]) counter++;
        std::cout << counter << std::endl;
        return 0;
}