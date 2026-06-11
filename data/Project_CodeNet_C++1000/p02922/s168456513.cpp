#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double A, B;
    int ans;
    std::cin >> A >> B;

    if(A >= B){
        ans = 1;
    }else{
        ans = (int)round(ceil((B - A)/(A-1))) + 1;
    }

    if(B == 1){
        ans = 0;
    }

    std::cout << ans;
}
