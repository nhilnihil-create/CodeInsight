#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, W, ans = 0, ans_1;
    std::cin >> N;
    vector<int> ws(N);
    
    for(int i = 0; i < N; i++){
        std::cin >> W;
        ans = ans + W;
        ws[i] = W;
    } 

    for(int i = 0; i < N; i++){
        ans = ans - 2 * ws[i];
        if(ans < 0){
            if(-1 * ans < ans_1){
                ans = -ans;
            }else{
                ans = ans_1;
            }
            break;
        }
        ans_1 = ans;
    }

    std::cout << ans;
}