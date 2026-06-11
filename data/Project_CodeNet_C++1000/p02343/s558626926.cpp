#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 100000+2
int n,m;
int rank[MAXN],par[MAXN];
void input(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		rank[i]=0;
	}
	for(int j=0;j<n;++j){
		par[j]=j;
	}
}
int find(int x){
	if(x==par[x]) return x;
	else return par[x]=find(par[x]);
}
void tg(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	else{
		if(rank[x]>rank[y]){
			par[y]=x;
		}
		else{
			par[x]=y;
			if(rank[x]==rank[y]) rank[y]++;
		}
	}
}
int main(){
	input();
	int xx,yy,zz;
	for(int i=0;i<m;++i){
	    cin>>xx>>yy>>zz;
	    if(xx==0) tg(yy,zz);
	    else{
	    	int l=find(yy),g=find(zz);
	    	if(l!=g) cout<<"0"<<endl;
	    	else cout<<"1"<<endl;
	    }
	}
	return 0;
}