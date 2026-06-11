#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N],V,P;
bool check(int x){
	int res=V-(n-x+1)-(P-1);
	if(a[x]+m<a[P])return false;
	if(res<=0)return true;
	ll tot=0;
	for(int i=P;i<x;++i){
		tot+=(a[x]+m)-a[i];
	}
	return tot>=1LL*res*m;
}
int main(){
	n=read(),m=read(),V=read(),P=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	int l=P,r=n+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans<<endl;
	return 0;
}

