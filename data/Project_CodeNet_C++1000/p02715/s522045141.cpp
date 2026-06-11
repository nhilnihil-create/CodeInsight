#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;

long modpow(long a, long b){
    
    if(b == 0){
        return 1;
    } else if(a == 1){
        return 1;
    } else if(b == 1){
        return a;
    } else if(b % 2 > 0){
        return a * modpow(a, b - 1) % mod;
    } else {
        return modpow(a * a % mod, b / 2);
    }
}

int main(){
    
    long n, k, ans = 0;
    cin >> n >> k;
    
    vector<long> v(k+1, 0);
    
    for(long i = k; i > 0; i--){
        v[i] = modpow((k / i), n);
        
        for(long j = 2; j <= k / i; j++){
            v[i] -= v[j * i];
            if(v[i] < 0) v[i] += mod;
        }
    }
        
    for(long i = 1; i <= k; i++){
        ans += i * v[i] % mod;
        ans %= mod;
    }
    
    cout << ans << "\n";
    
    return 0;
}

