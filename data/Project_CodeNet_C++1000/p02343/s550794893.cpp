#include<iostream>
using namespace std;
const int MAXN=10000+8;
int par[MAXN];
int rank[MAXN];
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

int find(int x){
	if(par[x]==x){
		return x;
	}
	else return par[x]=find(par[x]);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	
	if(rank[x]<rank[y]){
		par[x]=y;
	}
	else par[y]=x;
	if(rank[x]==rank[y]) rank[x]++;
}
bool same(int x,int y){
	return find(x)==find(y);
}

int main(){
	int n,q;
	int a,s,j;
	cin>>n>>q;
	init(n);
	for(int i=0;i<q;i++){
		cin>>a>>s>>j;
		if(a==0) unite(s,j);
		if(a==1) cout<<same(s,j)<<endl;
	}
	return 0;
}