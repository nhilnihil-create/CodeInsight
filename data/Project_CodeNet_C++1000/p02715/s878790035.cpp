/*Code by Codercjh*/
#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long ll;
template<typename T>
inline void read(T &x){
	char c=getchar();T fh=0;bool f=false;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))fh=(fh<<1)+(fh<<3)+(c^48),c=getchar();
	x=f?-fh:fh;
	return;
}
const int mod=1e9+7;
int n,k;
ll qp(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)s=(s*a)%mod;
		a=(a*a)%mod;b>>=1;
	}
	return s;
}
ll ans,a[200005];
int main(){
    read(n),read(k);
	rf(i,k,1){
		ll tmp=qp(k/i,n);
		fr(j,2,k/i)tmp-=a[i*j];
		while(tmp<0)tmp+=mod;
		a[i]=tmp;
		ans=(ans+a[i]*i)%mod;
	}
	cout<<ans;
	return 0;
}
