#include<iostream>
using namespace std;

int main(){
    int N, A;
    int flg_ap = 1;

    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> A;
        if(A%2 == 0){
            if(A%3 !=0 && A%5 !=0){
                flg_ap = 0;
            }
        }
    }

    if(flg_ap == 1){
        std::cout << "APPROVED";
    }else{
        std::cout << "DENIED";
    }
}