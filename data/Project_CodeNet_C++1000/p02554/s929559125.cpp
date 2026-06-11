#include<iostream>
using namespace std;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    int ans;
    ans = modpow(10,N,1000000007)-modpow(9,N,1000000007)-modpow(9,N,1000000007)+modpow(8,N,1000000007);
    cout << (ans+10000000070) % 1000000007 << endl;
    return 0;
}
