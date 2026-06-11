#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N, A, B_prev, B;
    long long ans = 0;

    std::cin >> N;
    vector<int> Bs(N);

    for(int i = 0; i < N-1; i++){
        std::cin >> B;
        if(i == 0){
            ans = ans + B;
        }else{
            ans = ans + min(B, B_prev);
        }
        B_prev = B;
    }
    ans = ans + B;

    std::cout << ans;
}