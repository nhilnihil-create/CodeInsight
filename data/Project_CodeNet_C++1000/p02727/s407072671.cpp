#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int x,y,a,b,c;
	// nyuryoku
	cin >> x >> y >> a >> b >> c;
	long long p[a],q[b],r[c];
	for(int i=0;i<a;i++){
		cin >> p[i];
	}
	for(int i=0;i<b;i++){
		cin >> q[i];
	}
	for(int i=0;i<c;i++){
		cin >> r[i];
	}
	LL ans = 0;
	sort(p,p+a,greater<LL>());
	sort(q,q+b,greater<LL>());
	sort(r,r+c,greater<LL>());
	// keisan
	LL s[x+y+c],iter = 0;
	for(int i=0;i<x;i++){
		s[iter] = p[i];
		iter++;
	}
	for(int i=0;i<y;i++){
		s[iter] = q[i];
		iter++;
	}
	for(int i=0;i<c;i++){
		s[iter] = r[i];
		iter++;
	}
	LL t = x + y + c; 
	sort(s,s+t,greater<LL>());
	for(int i=0;i<x+y;i++){
		ans += s[i];
	}
	cout << ans << endl;
}
