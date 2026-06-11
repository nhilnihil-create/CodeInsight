#include <bits/stdc++.h>
using namespace std;



long long mod = 2019;

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
	string S;
	cin >> S;
	int N = (int)S.length();
	long long T[N+1];
	long long CNT[2019];
	for(int i=0;i<2019;i++){
		CNT[i] = 0;
	}
	CNT[0] = 1;
	T[N] = 0;
	for(int i=N-1;i>=0;i--){
		T[i] = modplus(modmul((S[i] - '0'), modpow(10, N - i - 1)), T[i+1]);
		CNT[T[i]]++;
	}
	long long ans = 0;
	for(int i=0;i<2019;i++){
		ans += CNT[i] * (CNT[i] - 1) / 2;
		//if(CNT[i] > 0)cout << i << ":" << CNT[i] << endl;
	}
	cout << ans << endl;
}
