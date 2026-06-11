#include<iostream>
#include<cmath>
using namespace std;


int main(){
    string S;
    char c;
    int N;
    string ans = "Yes";

    std::cin >> S;
    N = S.size();

    for(int i = 0; i < N; i++){
        if((i + 1)%2 == 1){
            if(S[i] == 'L'){
                ans = "No";
            }
        }else{
            if(S[i] == 'R'){
                ans = "No";
            }
        }
    }
    std::cout << ans;



}