#include<iostream>
#include<vector>
using namespace std;

int main(){
    double N,K;
    double ans = 2.0;
    int num = 0;   
    std::cin >> N >> K;

    ans = N;
    while(ans>=1.0){
        ans = ans/K;
        num++;
    }

    std::cout << num;
}
