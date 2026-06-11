#include<iostream>
#include<string>
int main() {
        std::string S;
        std::cin >> S;
        if(S == "Sunny") std::cout << "Cloudy";
        else if(S == "Cloudy") std::cout << "Rainy";
        else std::cout << "Sunny";
}