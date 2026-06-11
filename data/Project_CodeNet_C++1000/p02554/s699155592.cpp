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

long modpow(long x, long y){
    if(y == 0){
        return 1;
    } else if (x == 0){
        return 0;
    } else if(x == 1){
        return 1;
    } else if(y % 2 > 0){
        return x * modpow(x, y-1) % mod;
    } else {
        return modpow(x * x % mod, y / 2);
    }
}

int main(){
    
    long n, ans = 0;
    cin >> n;
    
    ans += modpow(10,n);
    ans %= mod;
    ans -= (modpow(9,n) * 2 % mod);
    ans %= mod;
    ans += modpow(8,n);
    ans %= mod;
    if(ans < 0) ans += mod;
    
    cout << ans << "\n";
    
    return 0;
}

