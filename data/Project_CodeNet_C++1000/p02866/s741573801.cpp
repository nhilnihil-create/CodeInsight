#include <bits/stdc++.h>

int mod_num = 998244353;

int main(){
    int N;
    std::cin >> N;
    std::vector< int > cnt(N, 0);
    int max = 0;
    int tmp;
    std::cin >> tmp;
    if(tmp != 0){
        std::cout << 0 << std::endl;
        return 0;
    }
    cnt[0]++;
    for(int i=1; i<N; i++){
        int tmp;
        std::cin >> tmp;
        cnt[tmp]++;
        if(max < tmp){ max = tmp; }
    }
    if(cnt[0] != 1){
        std::cout << 0 << std::endl;
        return 0;
    }
    long long ans = 1;
    for(int i=0; i<max; i++){
        for(int j=0; j<cnt[i+1]; j++){
            ans = (ans * cnt[i]) % mod_num;
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
    
}

