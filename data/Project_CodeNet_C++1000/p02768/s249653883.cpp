#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL w = 1e9 + 7;

LL RepeatSquaring(LL N, LL P, LL M){
    if(P==0) return 1;
    if(P%2==0){
        LL t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


LL comb(LL n,LL a){
	LL ans = 1;
	LL wari = 1;
	for(LL i=n;i>=n-a+1;i--){
		ans = ans * i % w;
	}
	for(LL i=1;i<=a;i++){
		wari = wari * i % w;
	}
	return ans*modinv(wari,w)%w;
}

int main(){
	// sengen
	LL n,a,b,ans = 1;
	// nyuryoku
	cin >> n >> a >> b;
	// keisan
	if(n == 2){
		cout << '0' << endl;
		return 0;
	}
	ans = RepeatSquaring(2,n,w);
	ans = ans -1 - comb(n,a) - comb(n,b);
	ans %= w;
	if(ans < 0) ans += w;
	
	// syutsuryoku
	cout << ans << endl;
}