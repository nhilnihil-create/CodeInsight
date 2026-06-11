#include <bits/stdc++.h>
using namespace std;

long long n, k, result = 0, sizee;
long long MOD = 1000000007;
vector<long long> sizes(100001,0);

long long modpow(long long x, long long y, long long n) {
    long long res = 1;
    x%=n;
    while (y>0) {
        if (y%2==1) {
            res*=x;
            res%=n;
        }
        y/=2;
        x*=x;
        x%=n;
    }
    return res;
}

int main() {
    cin >> n >> k;
    for (long long i=k; i>=1; i--) {
        sizee = modpow(k/i,n,MOD);
        for (long long j=i+i; j<=k; j+=i) {
            sizee-=sizes[j];
        }
        sizes[i] = sizee;
        sizee*=i;
        sizee%=MOD;
        result+=sizee;
    }
    result%=MOD;
    cout << result;
    return 0;
}