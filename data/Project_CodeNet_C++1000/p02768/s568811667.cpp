#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long powmod(long long a, long long b){
    long long c = 1;
    while(b){
        if(b & 1) c = a * c % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

long long nCr(long long n, long long r){
    long long x = 1, y = 1;

    for(int i = 0; i < r; i++){
        x = x * (n - i) % mod;
        y = y * (i + 1) % mod;
    }
  
    return x*powmod(y,mod-2)%mod;
}

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = powmod(2, n) - 1 - nCr(n, a) - nCr(n, b);

    cout << (ans % mod + mod) % mod << endl;
    return 0;
}
