#include<iostream>
using namespace std;

int main(){
    int A,B,C;
    int flg_poor = 0;
    std::cin >> A >> B >> C;

    if(A==B && B==C){
        flg_poor = 0;
    }else if(A==B || B == C || C ==A){
        flg_poor = 1;
    }

    if(flg_poor == 1){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }
}