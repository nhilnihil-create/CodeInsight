#include <cstdio>
#include <vector>
using namespace std;
int n,m,q,maxx;
int a[55],b[55],c[55],d[55];
vector<int>v;
int check(){
	int sum=0;
	for(int i=0;i<q;++i){
		if(v[b[i]-1]-v[a[i]-1]==c[i])sum+=d[i];
	}
	return sum;
}
void dfs(int p){
	if(p==n){
		int res=check();
		if(maxx<res)maxx=res;
		return;
	}
	for(int i=v.back();i<=m;++i){
		v.push_back(i);
		dfs(p+1);
		v.pop_back();
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<q;++i)scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
	v.push_back(1);
	dfs(1);
	printf("%d\n",maxx);
	return 0;
}