#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10005
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
ll n,k,a[N],sum,x;
ll f[N],cnt=0,p[N],pn;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum+=a[i];
	}
	for(int i=1;i*i<=sum;i++){
		if(sum%i==0){
			f[++cnt]=i;
			if(i*i!=sum)f[++cnt]=sum/i;
		}
	}
	sort(f+1,f+cnt+1);
	for(int i=cnt;i>=1;i--){
		ll t=f[i],tot=0,o=0;
		for(int j=1;j<=n;j++){
			p[j]=a[j]%t;
			tot+=t-p[j];
		}
		if(tot==0){
			cout<<t<<endl;
			return 0;
		}
		sort(p+1,p+n+1);
		for(int j=1;j<=n;j++){
			o+=p[j];
			tot-=t-p[j];
			if(o==tot)break;
		}
		if(o<=k){
			cout<<t<<endl;
			return 0;
		}
	}
	return 0;
}
