#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
const int mod=1e9+7;
inline int read(){
	char c=getchar();int t=0,f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){t=(t<<3)+(t<<1)+(c^48);c=getchar();}
	return t*f;
}
int n,sta[maxn],rec[maxn];
char s[maxn];
signed main(){
	//freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);
	n=read();
	rec[0]=1;
	for(int i=1;i<=n;i++)
	rec[i]=rec[i-1]*i%mod;
	scanf("%s",s+1);
	int flag=0;
	int ans=1;
	for(int i=1;i<=2*n;i++){
		if((flag&1)&&(s[i]=='W')){
			flag++;
			sta[i]=1;
		}
		else if((flag&1)&&(s[i]=='B')){
			flag--;
			sta[i]=0;
		}
		else if(((flag%2==0))&&(s[i]=='B')){
			flag++;
			sta[i]=1;
		}
		else if(((flag%2==0))&&(s[i]=='W')) {
			flag--;
			sta[i]=0;
		}
		if(flag<0)break;
	}
	if(flag<0||flag>0){
		puts("0");
		return 0;
	}
	int now=0;
	for(int i=1;i<=2*n;i++){
		if(sta[i]==0){
			ans=(ans*((i-now-1)-now+mod))%mod;
			now=(now+1)%mod;
		}
	}
	for(int i=1;i<=2*n;i++){
		
	}
	printf("%lld\n",(ans*rec[n])%mod);
	return 0;
}
