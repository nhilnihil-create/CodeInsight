#include<iostream>
#include<vector>
using namespace std;

int main(){
    string S, ans;
    int N;
    int buff;

    std::cin >> N >> S;
    if(N%2 == 1){
        ans = "No";
    }else{
        ans = "Yes";
        for(int i = 0;i < N/2;i++){
            if(S[i] != S[i + N/2]){
                ans = "No";
            }
        }
    }
    std::cout << ans;

}