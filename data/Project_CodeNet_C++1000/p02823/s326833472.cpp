#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v,p;
int a[100005],b[100005],sum[100005];
map<int,int> tr[100005];
void upt(int x,int v,int c){
	while(x<=n) tr[x][v]+=c,x+=(x&-x);
}
int query(int x,int v){
	int res=0;
	while(x) res+=tr[x][v],x-=(x&-x);
	return res;
}
//m judges
//v problems
//first p problems
signed main(){
	int n,a,b;
	cin>>n>>a>>b;
	if(a>b) swap(a,b);
	if((b-a)%2==0) cout<<(b-a)/2;
	else cout<<min(a,n-b+1)+(b-a-1)/2;
	return 0;
} 
