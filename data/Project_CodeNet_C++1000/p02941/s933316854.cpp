#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 233;
int a[maxn],b[maxn],n;
bool inq[maxn];
long long ans = 0;
queue<int> q;
void check(int x){
	if(inq[x])return ;
	int l = x-1,r = x+1;
	if(l==0)l = n;
	if(r==n+1) r = 1;
	if(b[x]>b[l]+b[r]&&b[x]>a[x]){
		inq[x] = 1;
		q.push(x);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	memset(inq,0,sizeof(inq));
	for(int i=1;i<=n;i++)
		check(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		inq[x] = 0;
		int l = x-1,r = x+1;
		if(l==0)l = n;
		if(r==n+1) r = 1;
		int sum = b[l]+b[r];
		int v = (b[x]-a[x])/sum;
		b[x] -= sum*v;
		ans += v;
		check(l);check(r); 
//		cout<<"->"<<x<<endl;
//		for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
	}
	bool ok = 1;
	for(int i=1;i<=n;i++)	
		if(a[i]!=b[i]) ok = 0;
	if(!ok)puts("-1");
	else cout << ans << endl;
	return 0;
}