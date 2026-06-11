#include<bits/stdc++.h>
using namespace std;
int p[200005];
int u_find(int a){
	if(p[a]<0) return a;
	return p[a] = u_find(p[a]);
}
void merge(int a,int b){
	a = u_find(a);
	b = u_find(b);
	if(a==b) return;
	p[a]+=p[b];
	p[b] = a;
}
int main(){
	memset(p,-1,sizeof(p));
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
	int maxsize = 0;
	for(int i=1; i<=n; i++){
		maxsize = max(maxsize,-1*p[u_find(i)]);
	}
	cout<<maxsize;
}