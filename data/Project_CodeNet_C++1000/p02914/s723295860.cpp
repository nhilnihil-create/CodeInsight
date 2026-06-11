#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n;
ll a[maxn],ans,B,s,b[80];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),B^=a[i];
	for (int j=0;j<=62;j++)
		if ((B>>j)&1) {
			for (int i=1;i<=n;i++)
				if ((a[i]>>j)&1) a[i]-=1LL<<j;
			s+=1LL<<j;
		}
	for (int i=1;i<=n;i++) {
		for (int j=62;j>=0;j--)
			if (a[i]>>j) {
				if (!b[j]) { b[j]=a[i]; break; }
				a[i]^=b[j];
			}
	}
	for (int i=62;i>=0;i--)
		if (!((ans>>i)&1)&&b[i]) ans^=b[i];
	printf("%lld\n",ans*2+s);
	return 0;
}