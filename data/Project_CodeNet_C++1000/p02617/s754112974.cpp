#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin>>n;
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*i*(n-i+1);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v){
			swap(u,v);
		}
		ans-=1ll*u*(n-v+1);
	}
	cout<<ans<<endl;
	return 0;
}