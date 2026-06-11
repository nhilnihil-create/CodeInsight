#include<bits/stdc++.h>
using namespace std;
int n,m,h[100010],ma[100010],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		ma[i]=0;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		ma[a]=max(ma[a],h[b]);
		ma[b]=max(ma[b],h[a]);
	}
	for(int i=1;i<=n;i++)
		ans+=h[i]>ma[i];
	cout<<ans<<endl;
	return 0;
} 