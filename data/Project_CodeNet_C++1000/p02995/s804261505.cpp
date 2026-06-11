#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	LL a,b,c,d;
	// nyuryoku
	cin >> a >> b >> c >> d;
	LL multi = lcm(c,d);
	// keisan
	LL fc,fd,lc,ld,fm,lm;
	if(a%c == 0){
		fc = a/c;
	}else{
		fc = a/c + 1;
	}
	if(a%d == 0){
		fd = a/d;
	}else{
		fd = a/d + 1;
	}
	if(a%multi == 0){
		fm = a/multi;
	}else{
		fm = a/multi + 1;
	}
	lc = b/c; ld = b/d; lm = b/multi;
	LL ans = b - a + 1;
	if(lc >= fc){
		ans = ans - (lc - fc + 1);
	}
	if(ld >= fd){
		ans = ans - (ld - fd + 1);
	}
	if(lm >= fm){
		ans = ans + (lm - fm + 1);
	}
	cout << ans << endl;
	// syutsuryoku
}