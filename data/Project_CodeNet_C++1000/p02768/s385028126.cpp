#include <bits/stdc++.h>
using namespace std;

long long modpow (long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}


int main() {
	long long n;
	cin >> n;
	long long mod=1000000007;
	long long res=modpow(2,n,mod)-1;
	for(int i=0;i<2;i++){
		long long a;
		cin >> a;
		long long com=1;
		for(long long j=n;j>=n-a+1;j--){
			com=com*j%mod;
		}
		for(long long j=a;j>=1;j--){
			com=com*modinv(j,mod)%mod;
		}
		res-=com;
		if(res<0)res+=mod;
	}
	cout << res <<endl;
}
