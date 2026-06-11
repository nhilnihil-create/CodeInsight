#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 5050
inline int read(){
    int x=0,f=1;
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
int k,Q;
ll d[N],s[N];
int main(){
	k=read(),Q=read();
	for(int i=0;i<k;i++){
		d[i]=read();
		s[i]=s[i-1]+d[i];
	}
	while(Q--){
		ll n=read(),x=read(),m=read();
		x%=m;
		ll p=(n-1)/k,ans=n;
		ll sum=x,tmp=0,qwq=0;
		for(int i=0;i<k;i++){
			tmp+=d[i]%m;
			if(d[i]%m==0)qwq++;
		}
		sum+=tmp*((n-1)/k);
		ans-=((n-1)/k)*qwq;
		ll res=(n-1)-((n-1)/k*k);
		for(int i=0;i<res;i++){
			sum+=d[i]%m;
			if(d[i]%m==0)--ans;
		}
		printf("%lld\n",ans-1-sum/m);
	}
	return 0;
}
