#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#define IL inline
#define reg register
#define LL long long
#define N 500010
#define EPS 1e-5
using namespace std;

LL T,n,i,j,k,x,y,z;
LL a[N],b[N];

LL l,r,mid,ans;

IL bool Check(LL x){
	reg LL i=0,s=0,p=0;
	for (i=1;i<=n;i++){
		if (a[i]<=x)	continue;
		p=(LL)(a[i]/x);
		if (a[i]>p*x)	s+=p;
		else s+=p-1;
	}
	if (s<=k)	return 1;
	else return 0;
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	scanf("%lld%lld",&n,&k);
	for (i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for (i=1;i<=n;i++)	a[i]*=2;
	sort(a+1,a+1+n);
	a[0]=0;
	for (i=1;i<=n;i++)	a[0]+=a[i];
/*	if (a[0]<=k){
		cout<<"0"<<endl;
		return 0;
	}
	if (a[0]-n <=k ){
		cout<<"1"<<endl;
		return 0;
	}*/
	if (!k){
		printf("%lld\n",a[n]/2);
		return 0;
	}
	l=1;	r=a[n]*2;
	while (l<=r){
		mid=(l+r)>>1;
		if (Check(mid))	ans=mid,r=mid-1;
		else l=mid+1;
	}
	while (ans>1 && Check(ans-1))	ans--;
	while (!Check(ans))	ans++;
	if (ans&1)	cout<<(ans+1)/2<<endl;
	else cout<<ans/2<<endl;
	return 0;
}