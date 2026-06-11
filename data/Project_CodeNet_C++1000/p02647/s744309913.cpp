#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(4e7);
const int maxn=(2e5)+10;
int n,k,a[maxn],b[maxn];

int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	k=min(k,INF/n);
	while (k--) {
		for (int i=1;i<=n;i++) b[i]=0;
		for (int i=1;i<=n;i++) b[max(1,i-a[i])]++,b[min(n+1,i+a[i]+1)]--;
		for (int i=1;i<=n;i++) b[i]+=b[i-1];
		for (int i=1;i<=n;i++) a[i]=b[i];
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
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