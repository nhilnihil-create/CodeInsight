#include<iostream>
#include<string>
int main(){
        std::string S;
        std::string result ="Good";
        std::cin >> S;
        for(int i = 0; i < 3; i++)
                if(S[i] == S[i+1]) result ="Bad";
        std::cout << result;

}