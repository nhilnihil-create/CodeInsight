#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
inline ll read(){
	ll res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){res=(res<<3)+(res<<1)+ch-'0';ch=getchar();}
	return res*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10|'0');
}
const int N=1e6;
int n,a[N],sum[N],x;
signed main(){
	n=read();
	for(int i=1;i<=n;i++) x=read(),++sum[++a[x]];
	for(int i=1;i<=n+5;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++){
		int ans=0;
		int l=1,r=n+5;
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid*i<=sum[mid]) ans=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
}