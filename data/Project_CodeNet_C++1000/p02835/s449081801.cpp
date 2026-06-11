#include<iostream>
#include<vector>
using namespace std;

int main(){
    int A1, A2, A3;
    int ans = 0;
    std::cin >> A1 >> A2 >> A3;
    ans = A1 + A2 + A3;

    if(ans > 21){
        std::cout << "bust";
    }else{
        std::cout << "win";
    }
}