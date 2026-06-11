#include <bits/stdc++.h>

std::string L;
long long mod = 1e9 + 7;

long long modpow(long long a, long long n) {
    long long res = 1;
    while(n > 0) {
        if(n & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long calc(int n, bool max){
    if(L.size() == n){
        return 1;
    }
    if(L[n] == '1'){
        long long tmp = (2 * calc(n + 1, max)) % mod;
        tmp = (tmp + modpow(3, L.size() - n - 1)) % mod;
        return tmp;
    }else{
        if(max){
            return (calc(n + 1, true)) % mod;
        }else{
            return (3 * calc(n + 1, false)) % mod;
        }
    }
}

int main(){
    std::cin >> L;
    
    std::cout << calc(0, true) << std::endl;
    
    return 0;
}

