#include<iostream>
using namespace std;

int main(){
    int H, A, n, ans;

    std::cin >> H >> A;
    n = H%A;
    ans = (H - n)/A;
    if(n == 0){
        std::cout << ans;
    }else{
        std::cout << ans + 1;
    }

}