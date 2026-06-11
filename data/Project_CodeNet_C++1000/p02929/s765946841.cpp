#include<cstdio>
#define ll long long
#define mod 1000000007
#define maxn 100010
char s[2*maxn];
int a[2*maxn];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int flag=0;
	for(int i=1;i<=2*n;i++){
		if((s[i]=='B')==flag)a[i]=-1;
		else a[i]=1;
		flag^=1;
	}
	int sum=0;
	for(int i=1;i<=2*n;i++)
		sum+=a[i];
	if(sum){
		puts("0"); return 0;
	}
	ll ans=1,cnt=0;
	for(int i=1;i<=2*n;i++)
		if(a[i]==1)++cnt;
		else ans=ans*cnt%mod,--cnt;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	printf("%lld\n",ans);
	return 0;
}