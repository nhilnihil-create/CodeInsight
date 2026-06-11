#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long mod = 1000000007LL;

long long fastPow(long long x, long long n){
    if(n == 0){
        return 1LL;
    }
    if(n % 2 == 0){
        return (fastPow((x * x) % mod, n / 2)) % mod;
    }
    if(n % 2 == 1){
        return (x * fastPow(x, n - 1)) % mod;
    }
    return -1LL;
}

int main()
{
    long long n, a, b;

    cin >> n >> a >> b;

    long long sum = 0;
    sum = fastPow(2, n) - 1;
    long long x = 1;
    long long y = 1;
    long long nCa = 1;
    long long nCb = 1;
    for (int i = 0; i < a; i++){
        x *= (n - i);
        x %= mod;
        y *= (i + 1);
        y %= mod;
    }
    nCa = (x * fastPow(y, mod - 2)) % mod;

    x = 1;
    y = 1;
    for (int i = 0; i < b; i++)
    {
        x *= (n - i);
        x %= mod;
        y *= (i + 1);
        y %= mod;
    }
    nCb = (x * fastPow(y, mod - 2)) % mod;

    sum -= nCa;
    sum = (sum + mod) % mod;
    sum -= nCb;
    sum = (sum + mod) % mod;

    cout << sum << endl;
}