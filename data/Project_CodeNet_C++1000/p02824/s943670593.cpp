#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v,p;
int a[100005],b[100005],sum[100005];
map<int,int> tr[100005];
void upt(int x,int v,int c){
	while(x<=n) tr[x][v]+=c,x+=(x&-x);
}
int query(int x,int v){
	int res=0;
	while(x) res+=tr[x][v],x-=(x&-x);
	return res;
}
//m judges
//v problems
//first p problems
signed main(){
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int ans=0,tot=0;
	for(int i=1;i<=n;++i)
		if(a[i]!=a[i-1]) b[i]=++tot;
		else b[i]=tot;
	v-=(p-1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	//for(int i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i){
		if(a[i]>=a[p]) ++ans;
		else{
			if(a[i]+m<a[p]) continue;
			int tmp1=max(v-(n-i+1),0ll)*m,tmp2=(i-p)*(a[i]+m)-(sum[i-1]-sum[p-1]);
			//cout<<i<<" "<<ans<<" "<<tmp1<<" "<<tmp2<<endl;
			if(tmp1<=tmp2) ++ans;
		}
	}
	cout<<ans;
	return 0;
} 
