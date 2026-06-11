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
char s[100005];
const int mod=1e9+7;
ll p3[100005];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    p3[0]=1;
    fr(i,1,n)p3[i]=(p3[i-1]*3)%mod;
    ll ans=p3[n],tmp=1;
    fr(i,1,n)
    	if(s[i]=='0')
    		ans=((ans-tmp*2*p3[n-i])%mod+mod)%mod;
		else
		    tmp=(tmp*2)%mod;
	printf("%lld\n",ans%mod);
	return 0;
}