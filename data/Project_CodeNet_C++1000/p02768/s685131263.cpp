#include <bits/stdc++.h>

using namespace std;

inline int ctoi(char c) { if(c < '0' || '9' < c) throw invalid_argument("ctoi error"); return c - '0'; }
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

template <typename T>
inline T gcd(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("gcd error: x <= 0 or y <= 0");
	
	if(x < y) swap(x, y);
	T r = x % y;

	while(r != 0){
		x = y;
		y = r;
		r = x % y;
	}

	return y;
}
template <typename T>
inline T lcm(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("lcm error: x <= 0 or y <= 0");

	return x * y / gcd(x, y);
}

long long int calc(long long int a, long long int b, long long int p){
	if(b == 0) return 1;
	else if(b % 2 == 0){
		long long int d = calc(a, b / 2, p);
		return (d * d) % p;
	}
	else{
		return (a * calc(a, b - 1, p)) % p;
	}
}

int main(){
	long long int MOD = 1'000'000'007;
	long long int n, a, b;
	cin >> n >> a >> b;

	long long int ans = calc(2, n, MOD) - 1;

	long long int div = 1;
	for(long long int i = max(n, a); max(n, a) - min(n, a) < i; i--){
		div *= i;
		div %= MOD;
	}
	for(long long int i = 1; i <= min(n, a); i++){
		div *= calc(i, MOD - 2, MOD);
		div %= MOD;
	}

	ans += MOD;
	ans -= div;
	ans %= MOD;

	div = 1;
	for(long long int i = max(n, b); max(n, b) - min(n, b) < i; i--){
		div *= i;
		div %= MOD;
	}
	for(long long int i = 1; i <= min(n, b); i++){
		div *= calc(i, MOD - 2, MOD);
		div %= MOD;
	}
	
	ans += MOD;
	ans -= div;
	ans %= MOD;

	cout << ans << endl;

	return 0;
}