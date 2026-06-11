#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=3010;
int n,S,a[maxn],iv2,dp[maxn][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(S);
	for (int i=1;i<=n;i++) read(a[i]);
	iv2=mod-mod/2;
	dp[0][0]=ksm(2,n);
	for (int i=0;i<n;i++)
	for (int j=0;j<=S;j++) {
		if (j+a[i+1]<=S) update(dp[i+1][j+a[i+1]],(ll)dp[i][j]*iv2%mod);
		update(dp[i+1][j],dp[i][j]);
	}
	printf("%d\n",dp[n][S]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/