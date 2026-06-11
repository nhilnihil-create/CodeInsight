#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}

const int N = 100005;
typedef long long ll;

int n,m,v,p;
int a[N];
ll s[N];
bool cmp(int x,int y) { return x>y; }

int main()
{
	n=read(); m=read(); v=read(); p=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int ans=p,x=0,y,z,ok=1;
	ll t;
	for(int i=p+1;i<=n;i++){
		if(a[i]==a[i-1]) { ans+=ok; continue; }
		y=n-i+1;
		while(a[x+1]>a[i]+m) x++;
		if(x>=p) break;
		if(x+y>=v) { ok=1; ans++; }
		else {
			z=v-x-y;
			t=1ll*(p-1-x)*m+1ll*(a[i]+m)*(i-p)-(s[i-1]-s[p-1]);
			if(t>=1ll*m*z) ok=1,ans++;
			else ok=0;
		}
	}
	printf("%d\n",ans);
	
	return 0;
}