#include <bits/stdc++.h>

int main(){
    long long N;
    std::cin >> N;
    if(N == 2){
        std::cout << 1 << std::endl;
        return 0;
    }
    int ans = 2;
    int max = (int)std::sqrt(N);
    for(int i=2; i<=max; i++){
        long long N_tmp = N;
        if(N_tmp % i == 0){
            while(N_tmp % i == 0){
                N_tmp = N_tmp / i;
            }
            if(N_tmp  % i == 1){
                ans++;
            }
        }else if(N_tmp % i == 1){
            if((N-1) / i == i){
                ans++;
            }else{
                ans += 2;
            }
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}

