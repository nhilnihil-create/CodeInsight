#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int f[200005];
int fa[200005];
int find(int x){
	return x != f[x]?f[x]=find(f[x]):x;
}

void join(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) f[fx] = fy;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i] = i;
	
	for(int i=1;i<=m;i++){
		int aa,bb;
		cin>>aa>>bb;
		join(aa,bb);	
	}
	
    for(int i=1;i<=n;i++) fa[i] = find(f[i]);
	int ans = -inf;
	sort(fa+1,fa+1+n);
	int num = 1;
	for(int i=2;i<=n;i++){
		if(fa[i] == fa[i-1]) ++num;
		else ans = max(ans,num),num=1;
	}
	cout<<max(ans,num)<<endl;
	return 0;
}