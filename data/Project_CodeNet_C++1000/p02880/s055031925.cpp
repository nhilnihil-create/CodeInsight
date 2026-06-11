#include<iostream>
using namespace std;

int main(){
    int N;
    string ans = "No";

    std::cin >> N;

    for(int i = 1; i <=9; i++){
        if(N%i == 0){
            if(N/i < 10){
                ans = "Yes";
            }
        }
    }
    std::cout << ans;


}