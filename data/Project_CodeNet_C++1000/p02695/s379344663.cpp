#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100],b[100],c[100],d[100];
int ans;
vector<int> v;
void dfs(int x,int deep){
	if (deep==n){
		int num=0;
		for (int i=0;i<q;i++) if (abs(v[b[i]-1]-v[a[i]-1])==c[i]) num+=d[i];
		ans=max(ans,num);
		return ;
	}
	for (int i=x;i<=m;i++){
		v.push_back(i);
		dfs(i,deep+1);
		v.erase(v.begin()+v.size()-1);
	}
	return ;
}
int main(){
	cin>>n>>m>>q;
	for (int i=0;i<q;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}