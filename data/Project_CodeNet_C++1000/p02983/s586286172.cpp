#include<iostream>
#include<vector>
#include<string>

using ll = long long;
const int MOD = 2019;

int main(){
    ll L, R;
    std::cin >> L >> R;

    int L_rest = L % MOD;
    int R_rest = R % MOD;

    if(R - L >= MOD || R_rest <= L_rest){
        // LとRの間に余り0が存在
        std::cout << 0 << std::endl;
    }else{
        int minVal = MOD;
        for(int i = L_rest; i <= R_rest; i++){
            for(int j = i + 1; j <= R_rest; j++){
                minVal = std::min(minVal, (i * j) % MOD);
            }
        }
        std::cout << minVal << std::endl;
    }
    
    return 0;
}
