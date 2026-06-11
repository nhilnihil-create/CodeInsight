#include<bits/stdc++.h>
using namespace std;

const int N = 105;
typedef long long LL;

int n;
char s[N];
LL ans, f[N][3], k, g[N][3];

int main() {
	cin>>(s + 1)>>k;
	n = strlen(s + 1);
	f[1][0] = 0, f[1][1] = 0, f[1][2] = 1;
	g[1][0] = 1, g[1][1] = 1e9, g[1][2] = 1;
	for(int i = 2; i <= n; i++) {
		if(s[i] == s[i - 1]) {
			f[i][1] = f[i - 1][2];
			f[i][2] = f[i - 1][0] + 1;
			g[i][1] = g[i - 1][2];
			g[i][2] = g[i - 1][0] + 1;
		}
		else {
			f[i][1] = f[i - 1][0];
			f[i][2] = f[i - 1][0] + 1;
			g[i][1] = g[i - 1][0];
			g[i][2] = g[i - 1][0] + 1;
		}
		g[i][0] = min(g[i][1], g[i][2]);
		f[i][0] = min(f[i][1], f[i][2]);
	}
	if(s[1] != s[n]) 
		cout<<f[n][0]*k<<endl;
	else {
		ans = min(f[n][2]*(k - 1) + f[n][0], g[n][0]*(k - 1) + f[n][0]);
		if(k&1) ans = min(ans, f[n][0]*(k + 1)/2 + g[n][2]*(k - 1)/2);
		else ans = min(ans, f[n][0]*k/2 + g[n][2]*(k/2 - 1) + g[n][0]);
		cout<<ans<<endl;
	}
}
