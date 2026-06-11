#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL wari = 1e9 + 7;

LL kaijo(LL n){
	if(n == 0) return 1;
	return n*kaijo(n-1)%wari;
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

int main(){
	// sengen
	LL x,y;
	cin >> x >> y;
	if((x+y)%3 != 0){
		cout << '0' << endl;
      return 0;
	}
	// nyuryoku
	LL n,m;
	m = (2*x - y)/3;
	n = (2*y - x)/3;
	if(n < 0 || m < 0){
		cout << '0' << endl;
      return 0;
	}
	// keisan
	cout << kaijo(n+m)*modinv(kaijo(n),wari)%wari*modinv(kaijo(m),wari)%wari << endl;
	// syutsuryoku
}