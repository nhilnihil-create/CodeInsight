#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int arr[11];
int a[55];
int b[55];
int c[55];
int d[55];
int maxscore = 0;
void solve(){
	int score = 0;
	for(int i=0; i<q; i++){
		if(arr[b[i]]-arr[a[i]]==c[i]) score+=d[i];
	}
	maxscore = max(maxscore,score);
}
void dfs(int curr,int start){
	for(int i=start; i<=m; i++){
		arr[curr] = i;
		if(curr==n) solve();
		else dfs(curr+1,i);
	}
}
int main(){
	cin>>n>>m>>q;
	for(int i=0; i<q; i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	dfs(1,1);
	cout<<maxscore;
}