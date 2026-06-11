#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int N, a[MAXN], ti[MAXN], flag, tim;
int prime[MAXN], vis[MAXN], tot;
void sieve(int N) {
	vis[1] = 1;
	for(int i = 2; i <= N; i++) {
		if(!vis[i]) prime[++tot] = i; 
		for(int j = 1; j <= tot && 1ll * i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1;
			if(!(i % prime[j])) break;
		}
	}
}
void solve(int x) {
	int lim = sqrt(x) + 1;
	for(int j = 1; 1ll * prime[j] * prime[j] <= x && j <= tot; j++) {
		int i = prime[j];
		if(x % i == 0) {
			ti[i]++;
			if(ti[i] == 2) {flag = 1; return ;}
			while(x % i == 0) x /= i;
		}
	}
	if(x != 1) {
		ti[x]++;
		if(ti[x] == 2) {
			flag = 1; return ;
		}
	}
}

int main() {
//	freopen("a.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	N = read();
	sieve(N);
//	for(int i = 1; i <= tot; i++) cout << prime[i] << ' ';
	for(int i = 1; i <= N; i++ ) {
		a[i] = read();
		solve(a[i]);
	}
	if(!flag) {puts("pairwise coprime"); return 0;}
	int g = a[1];
	for(int i = 2; i <= N; i++) {
		g = __gcd(g, a[i]);
	}	
	if(g == 1)  {puts("setwise coprime"); return 0;}
	puts("not coprime");

	return 0;
}