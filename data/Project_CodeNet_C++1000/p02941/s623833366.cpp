#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int a[N],b[N],n;
struct cmp{
	bool operator()(const int x,const int y){
		return b[x]>b[y];
	}
};
priority_queue<int,vector<int>,cmp>q;
void pl(){
	printf("%d\n",-1); exit(0);
}
int nxt(int x){return x==n?b[1]:b[x+1];}
int pre(int x){return x==1?b[n]:b[x-1];}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) 
	if (b[i]<a[i]) pl(); else if (b[i]>a[i]&&b[i]>pre(i)+nxt(i)) q.push(i); 
	int k=0;
	ll ans=0;
	while (!q.empty()) {
		int t=q.top(); q.pop();
//		cout << t << endl;
		if (t==k) pl(); k=t;
		int sum=pre(t)+nxt(t);
		if ((b[t]-a[t])%sum==0) ans+=(b[t]-a[t])/sum,b[t]=a[t];
		else {
			ans+=b[t]/sum;
			b[t]%=sum;
			if (b[t]<a[t]) pl();
		}
		int x=t-1; if (x<=0) x=n;
		if (b[x]>pre(x)+nxt(x)&&b[x]>a[x]) q.push(x);
		x=t+1; if (x>n) x=1;
		if (b[x]>pre(x)+nxt(x)&&b[x]>a[x]) q.push(x);
	}
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) pl();
	printf("%lld\n",ans);
}