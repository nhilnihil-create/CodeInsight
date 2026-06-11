#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 300005;
int n, s[MX], m = 1, a[MX], c = -1, t, b[20];

int main(){
	scanf("%d", &n); b[n]++;
	rep(i,n) m *= 2;
	rep(i,m) scanf("%d", s+i);
	sort(s,s+m, greater<int>());
	rep(i,m) if(s[i] != s[i+1]){
		a[t++] = i-c;
		c = i;
	}
	rep(i,t){
		int ac = 0, u = 0;
		for(int j = n; j >= 0; j--){
			u = ac;
			ac = min(u + b[j], a[i]);
			b[j] = u*2 + b[j] - ac;
		}
		if(ac < a[i]) return 0*puts("No");
	}
	puts("Yes");
}