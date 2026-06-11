#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=5010;
int k,q,a[maxn],d[maxn];
int n,x,m;
ll sum,ans;
int b[maxn];
ll F(ll A) {
	if (A<0) return 0;
	return A/k+1;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(k); read(q);
	for (int i=0;i<k;i++) read(a[i]);
	while (q--) {
		read(n); read(x); read(m);
		x%=m;
		for (int i=0;i<k;i++) d[i]=a[i]%m;
		d[k]=d[0];
		
		ans=0;
		for (int i=0;i<k;i++) {
			if (!d[i]) {
				//d[i]->d[i+1]
				//0<=i+?k<n
				ans+=F(n-i-2);
			//	printf("%lld\n",n-i-1);
			}
		}
		//printf("%lld\n",ans);
		sum=x;
		for (int i=0;i<k;i++) {
			// 0<=i+?k<n-1
			sum+=(ll)F(n-i-2)*d[i];
		}
		//printf("sum=%lld\n",sum);
		ans+=sum/m-x/m;
		printf("%lld\n",n-1-ans);
	}
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