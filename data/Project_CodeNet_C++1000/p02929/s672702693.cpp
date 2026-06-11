#include<cstdio>
typedef long long ll;
const int mod=1000000007;
char s[200050];
bool d[200050];
int sum[200050];
int main(){
	int n,i,ans=1,cnt=0;
	scanf("%d%s",&n,s+1);
	if(s[1]=='W'||s[n<<1]=='W'){
		puts("0");
		return 0;
	}
	for(i=2,d[1]=0,sum[1]=1;i<=(n<<1);++i)sum[i]=sum[i-1]+!(d[i]=d[i-1]^(s[i]==s[i-1]));
	if(sum[n<<1]!=n){
		puts("0");
		return 0;
	}
	for(i=2;i<=(n<<1);++i)if(d[i]){
		ans=(ll)ans*(sum[i-1]-cnt)%mod;
		++cnt;
	}
	for(i=2;i<=n;++i)ans=(ll)ans*i%mod;
	printf("%d\n",ans);
	return 0;
}