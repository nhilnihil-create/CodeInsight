#include <bits/stdc++.h>

long long modnum = 1e9 + 7;

long long modpow(long long a, long long n) {
    long long res = 1;
    while(n > 0) {
        if(n & 1){
            res = res * a % modnum;
        }
        a = a * a % modnum;
        n >>= 1;
    }
    return res;
}

int main(){
    int N, K;
    std::cin >> N >> K;
    
    std::vector< int > num(K);
    long long ans = 0;
    for(int i=K; i>0; i--){
        long long tmp;
        int pat = K / i;
        tmp = modpow(pat, N);
        for(int j=i+i; j<=K; j=j+i){
            if(tmp < num[j]){
                tmp = modnum + tmp - num[j];
            }else{
                tmp = tmp - num[j];
            }
        }
        num[i] = tmp;
        tmp = (tmp * i) % modnum;
        ans = ( ans + tmp) % modnum;
    }
    
    std::cout << ans << std::endl;
    return 0;
}

