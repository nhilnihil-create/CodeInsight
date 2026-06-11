#include<iostream>
#define MAXN 100000+10
using namespace std;
int par[MAXN];
int rank[MAXN];
int re[MAXN];
int n,q;
void init(){
	int i;
	for (i = 0;i < n;++i){
		rank[i]=0;
		par[i]=i;
	}
}

int find(int x){
	if (x == par[x]) return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if (x == y) return;
	if (rank[x] < rank[y]) par[x]=par[y];
	else par[y]=par[x];
	if (rank[x] == rank[y]) rank[x]++;
	
}

int main(){
	int a,b,ord,i;
	int tot=0,p1,p2;
	cin>>n>>q;
	init(); 
	for (i = 0;i < q;++i){
		cin>>ord;
		cin>>a>>b;
		if (ord == 0){
			unite(min(a,b),max(a,b));
		}
		else if (ord == 1){
			p1=find(a);
			p2=find(b);
			if (p1 == p2) re[tot++]=1;
			else re[tot++]=0;
		}
	}
	for (i = 0;i < tot;++i)
		cout<<re[i]<<endl;
	return 0;
} 