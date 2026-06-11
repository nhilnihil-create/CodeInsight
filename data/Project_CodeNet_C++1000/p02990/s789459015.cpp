#include <bits/stdc++.h>

int MAX = 3000;
long long modnum = 1e9 + 7;
std::vector< long long > fac(MAX);
std::vector< long long > finv(MAX);
std::vector< long long > inv(MAX);

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % modnum;
        inv[i] = modnum - inv[modnum%i] * (modnum / i) % modnum;
        finv[i] = finv[i - 1] * inv[i] % modnum;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % modnum) % modnum;
}

int main(){
    int N, K;
    std::cin >> N >> K;
    
    COMinit();
    
    long long blue = K;
    long long red = N - K;
    std::vector< long long > ans(K);
    for(int i=1; i<=K; i++){
        if(red + 1 < i){
            ans[i - 1] = 0;
        }else{
            long long b = COM(blue - 1, i - 1);
            long long r = COM(red + 1, i);
            ans[i - 1] = (b * r) % (long long)modnum;
        }
    }
    
    for(int i=0; i<K; i++){
        std::cout << ans[i] << std::endl;
    }
    
    return 0;
}

