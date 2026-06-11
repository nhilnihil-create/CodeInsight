#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=2147483647;
const double pi=3.1415926535897932384626;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxn=2e5+5;
int n,a[maxn],b[maxn];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=read();
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if(n&1) printf("%d\n",b[(n+1)>>1]-a[(n+1)>>1]+1);
	else printf("%d\n",b[(n+2)>>1]+b[n>>1]-a[(n+2)>>1]-a[n>>1]+1);
	return 0;
}
