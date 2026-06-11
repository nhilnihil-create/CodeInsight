#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int f[200005]={0};
int sz[200005]={0};
int n,m;
int ans=1;
int get(int x)
{
	if(x==f[x])return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y)
{
	int xx=get(x);
	int yy=get(y);
	if(xx!=yy){
		f[xx]=yy;
		sz[yy]+=sz[xx];
		ans=max(ans,sz[yy]);
	}
	
}
void init()
{
	for(int i=1;i<=n;i++){
		f[i]=i;
		sz[i]=1;
	}
}
int main(){
    cin>>n>>m;
    init();
    while(m--){
    	int x,y;
    	cin>>x>>y;
    	merge(x,y);
	}
	cout<<ans<<endl;
}