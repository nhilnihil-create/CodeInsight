#include<iostream>
using namespace std;

int S, W;

int main(){
    std::cin >> S >> W;
    if(W>=S){
        std::cout << "unsafe";
    }else{
        std::cout << "safe";
    }
}