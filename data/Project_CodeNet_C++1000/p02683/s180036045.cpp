#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
using namespace std;
const int MAXN=20;
typedef long long ll;
int a[MAXN][MAXN],vis[MAXN],ans[MAXN],mon[MAXN];
int n,m,x,sum=0,price=1e9;
void dfs(int pos){
	if(pos==n+1){
		for(int i=1;i<=m;i++) if(ans[i]<x) return;
		price=min(price,sum); 
		return;
	}
	dfs(pos+1);
	for(int j=1;j<=m;j++) ans[j]+=a[pos][j];
	sum+=mon[pos];
	dfs(pos+1);
	for(int i=1;i<=m;i++) ans[i]-=a[pos][i];
	sum-=mon[pos];
}
int main()
{
	ios;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		cin>>mon[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dfs(1);
	if(price==1e9) cout<<-1<<'\n';
	else cout<<price<<'\n';
	return 0;
}