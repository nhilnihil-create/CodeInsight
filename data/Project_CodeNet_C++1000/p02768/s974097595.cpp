#include <bits/stdc++.h>
using namespace std;


long long mod = 1000000000 + 7;

long long modplus(long long a, long long b){
	long long ans = a + b;
	ans %= mod;
	return ans;
}

long long modminus(long long a, long long b){
	long long ans = a - b;
	ans %= mod;
	if(ans < 0) ans += mod;
	return ans;
}

long long modmul(long long a, long long b){
	long long ans = (a % mod) * (b % mod);
	ans = ((ans % mod) + mod) % mod;
	return ans;
}

long long modpow(long long A, long long P){
	long long a = A, p = P;
	if(p == 0) return 1;
	if(p == 1) return a;
	long long adash = modmul(a,a);
	if(p % 2) return modmul(modpow(adash, p / 2), a);
	else return modpow(adash, p / 2);
}

long long moddiv(long long a, long long b){
	long long divisor = modpow(b, mod - 2);
	return modmul(a,divisor);
}

int main(){
	long long n, a, b;
	cin >> n >> a >> b;
	long long ans = modpow(2, n);
	long long tmpa = 1;
	long long tmpb = 1;
	for(long long i=0;i<a;i++){
		tmpa = modmul(tmpa, n - i);
	}
	for(long long i=0;i<a;i++){
		tmpa = moddiv(tmpa, i + 1);
	}
	for(long long i=0;i<b;i++){
		tmpb = modmul(tmpb, n - i);
	}
	for(long long i=0;i<b;i++){
		tmpb = moddiv(tmpb, i + 1);
	}
	ans = modminus(ans, tmpa);
	ans = modminus(ans, tmpb);
	ans = modminus(ans, 1);
	cout << ans << endl;
}
