#include<bits/stdc++.h>
using namespace std;
inline void E(){puts("-1");exit(0);}
typedef long long ull;
const int N=1e5+5;
int n,i,a[N];ull l[N],r[N],ans,v[N];
int main(){
	scanf("%d",&n);
	for(i=0;i<=n;++i)scanf("%d",a+i);
	l[0]=r[0]=1;
	for(i=0;i<n;++i){
		if(r[i]<=a[i])E();
		if(l[i]<=a[i])l[i+1]=1;else l[i+1]=l[i]-a[i];
		r[i+1]=r[i]-a[i]<<1;r[i+1]=min(r[i+1],1ll<<50);
	}
	if(l[n]>a[n] || r[n]<a[n])E();
	v[n]=a[n];
	for(i=n-1;i>=0;--i){
		v[i]=min(r[i],v[i+1]+a[i]);
	}
	for(i=0;i<=n;++i)ans+=v[i];
	cout<<ans<<endl;
}