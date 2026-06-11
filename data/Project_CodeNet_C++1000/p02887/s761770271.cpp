#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    string S;
    int N, ans;
    char c = '1';

    std::cin >> N >> S;
    ans = N;

    for(int i = 0; i < N; i++){
        if(S[i] == c){
            ans--;
        }
        c = S[i];
    }

    std::cout << ans;
}
