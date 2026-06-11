#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int cnt;

int dfs(int nn){
	if(nn==n){cnt++;return 0;}
	else if(nn>n){return 0;}
	dfs(nn+1);
	dfs(nn+2);
	dfs(nn+3);
	return 0;
}

int main(){
	while(cin>>n){
		cnt=0;
		if(!n)break;
	dfs(0);
	cout<<cnt/10/365+1<<endl;
	}
}