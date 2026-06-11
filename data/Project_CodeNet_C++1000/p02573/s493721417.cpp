#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,ans=0,father[N],sum[N];
int Findfather(int x){
    return father[x]==x?x:father[x]=Findfather(father[x]);
}
void Union(int x,int y){
    x=Findfather(x);
	y=Findfather(y);
    if(x!=y){
    	father[y]=x;
		sum[x]+=sum[y];
	}
}
void init(){
    for(int i=0;i<=n;i++){
    	father[i]=i,sum[i]=1;
	}
}
int main(){
    cin>>n>>m;
    init();
    while(m--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    for(int i=1;i<=n;i++){
    	if(Findfather(i)==i){
    		ans=max(ans,sum[i]);
		}
	}
    cout<<ans;
    return 0;
}