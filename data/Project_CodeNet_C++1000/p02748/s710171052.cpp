#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
	int A,B,m,ans,Amin=1e5,Bmin=1e5;
	cin>>A>>B>>m;
	for(int i=1;i<=A;++i)
		cin>>a[i],Amin=min(Amin,a[i]);
	for(int i=1;i<=B;++i)
		cin>>b[i],Bmin=min(Bmin,b[i]);
	int x,y,c;
	ans=Amin+Bmin;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>c;
		ans=min(ans,a[x]+b[y]-c);
	}
	cout<<ans;
	return 0;
}