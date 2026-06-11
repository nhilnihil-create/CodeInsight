#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF = 1e9 + 100;
const lli INF64 = (1LL << 61) + 100;
const lli MOD = 1e9 + 7;
const lli MH1 = 1599614977, MH2 = 2034417103, MH3 = 1090250123, MH4 = 2024491871; 
lli bpow(lli baseee, lli exponenttt) {
	if(exponenttt < 0) return 0;
	lli res = 1;
	baseee %= MOD;
	while (exponenttt > 0) {
		if ((exponenttt & 1) == 1) res = (res*baseee) % MOD;
		baseee = (baseee*baseee) % MOD;
		exponenttt >>= 1;
	}
	return res;
}
lli multInverse(lli a) {//if_mod_is_prime
	return bpow(a, MOD - 2);
}
lli divm(lli a, lli b) {//if_mod_is_prime
	return (a * multInverse(b)) % MOD;
}
lli multm(lli a, lli b) {
	return (a * b) % MOD;
}
lli subm(lli a, lli b) {
	a += MOD;
	lli r = a - b;
	if(r >= MOD) return r - MOD;
	return r;
}
lli addm(lli a, lli b) {
	lli r = a + b;
	if(r >= MOD) return r - MOD;
	return r;
}
set<lli> anss;
void check(lli nn, lli i) {
	while(nn % i == 0) nn /= i;
	if((nn - 1) % i == 0) anss.insert(i);
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	lli n;
	cin >> n;
	if(n == 2) {
		cout << "1\n";
		return 0;
	}
	anss.insert(n);
	for(lli i = 2; i*i <= n; i++) {
		if(n % i != 0) continue; 
		check(n, i);
		check(n, n/i);
	}
	lli mn = n - 1;
	anss.insert(mn);
	for(lli i = 2; i*i <= mn; i++) {
		if(mn % i == 0) {
			anss.insert(i);
			anss.insert(mn / i);
		}
	}
	cout << anss.size() << "\n";
	return 0;
}