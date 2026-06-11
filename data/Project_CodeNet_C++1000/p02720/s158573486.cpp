#include<bits/stdc++.h>
using namespace std;
int k,tot;
void dfs(int x,long long s,int f){
	if(x==1){
		tot++;
		if(tot==k){
			cout<<s;
			exit(0);
		}
		return;
	}
	if(f>0){
		dfs(x-1,s*10+f-1,f-1);
	}
	dfs(x-1,s*10+f,f);
	if(f<9){
		dfs(x-1,s*10+f+1,f+1);
	}
}
int main(){
	cin>>k;
	for(int i=1;i<=10;i++){
		for(long long j=1;j<=9;j++){
			dfs(i,j,j);
		}
	}
	return 0;
}
