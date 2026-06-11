#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int N, X, L;
    int count = 1;
    int D = 0;
    std::cin >> N >> X;

    for(int i = 0; i < N; i++){
        std::cin >> L;
        D = D+L;
        if(D <= X){
            count++;
        }else{
            break;
        }

    }
    std::cout << count;

}