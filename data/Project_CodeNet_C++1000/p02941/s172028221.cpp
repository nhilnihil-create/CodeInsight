#include<bits/stdc++.h>
#define N 200010 
#define p(x) (x==1?n:(x)-1)
#define s(x) (x==n?1:(x)+1)
#define pii pair<int,int>
#define fs first
#define sc second
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int x=0,f=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
priority_queue<pii ,vector<pii> > T;
int n,a[N],b[N];
ll ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	int cnt=n;
	for(int i=1;i<=n;i++)
		if(b[i]>a[i])	T.push(make_pair(b[i],i));
		else if(b[i]<a[i]) {puts("-1");return 0;}
		else cnt--;
	while(cnt)
	{
		pii v=T.top();T.pop();
		int t1,t2;
		t1=b[p(v.sc)]+b[s(v.sc)];
		t2=(v.fs-a[v.sc])/t1;
		//cout<<v.fs<<' '<<v.sc<<"  "<<t1<<' '<<t2<<endl;
		b[v.sc]=v.fs-t2*t1;
		if(t2<=0) {puts("-1");return 0;}
		if(b[v.sc]==a[v.sc]) cnt--;
		else T.push(make_pair(b[v.sc],v.sc));
		ans+=t2;
		
	}
	printf("%lld",ans);
	return 0;
}
