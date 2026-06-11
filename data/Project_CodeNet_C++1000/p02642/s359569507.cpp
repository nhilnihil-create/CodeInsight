#pragma GCC optimize(3)
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
const int N=2e5+10,M=1e6+10;
int n,a[N],vis[M],maxn,rp[M],ans;
set<int>st;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(st.count(x) )rp[x]=1;
		st.insert(x);
		maxn=max(maxn,x);
	}
	for(auto i:st){
		if(vis[i])continue;
		for(int j=2*i;j<=maxn;j+=i)
		vis[j]=1;
		ans+=!rp[i]&&!vis[i];
	}
	printf("%d\n",ans);
}