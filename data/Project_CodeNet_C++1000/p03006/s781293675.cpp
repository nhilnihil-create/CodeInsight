#include<bits/stdc++.h>
using namespace std;
int sz[55],f[55],x[55],y[55];
pair<int,int> Slope(int i,int j){
	return make_pair(x[j]-x[i],y[j]-y[i]);
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b){
	a=find(a);b=find(b);
	if(a!=b) sz[b]+=sz[a];
	f[a]=b;
}
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>y[i];
	int ans=n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			for(int k=1;k<=n;++k)
				f[k]=k,sz[k]=1;
			int tmp=0;
			merge(i,j);
			for(int k=1;k<=n;++k)
				for(int l=1;l<=n;++l)
					if(k!=l && Slope(k,l)==Slope(i,j))
						merge(k,l);
			for(int k=1;k<=n;++k)
				if(find(k)==k) ++tmp;
			ans=min(ans,tmp);
		}
	cout<<ans;
	return 0;
}