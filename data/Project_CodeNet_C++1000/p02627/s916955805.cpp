#include<iostream>
using namespace std;

int main(){
    char c;
    std::cin >> c;

    if((int)c > 96){
        std::cout << "a";
    }else{
        std::cout << "A";
    }
}