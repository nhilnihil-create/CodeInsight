#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=2002020;
int n,p,cnt[N],h[N]; char s[N];
void solve2(){
	long long ans=0;
	for(int i=1;i<=n;i++)
		if((s[i]-'0')%2==0)ans+=i;
	cout<<ans<<endl;
}
void solve5(){
	long long ans=0;
	for(int i=1;i<=n;i++)
		if((s[i]-'0')%5==0)ans+=i;
	cout<<ans<<endl;
}
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#undef int
int main()
{
	#define int long long
	n=read(); p=read();
	scanf("%s",s+1);
	if(p==2){solve2();return 0;}
	if(p==5){solve5();return 0;}
	int ans=0,nw=1; ++cnt[0];
	for(int i=n;i>=1;i--){
		h[i]=(1ll*nw*(s[i]-'0')%p+h[i+1])%p;
		ans+=cnt[h[i]]; cnt[h[i]]++; nw=10ll*nw%p;
	} cout<<ans<<endl;
	return 0;
}