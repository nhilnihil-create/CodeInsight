#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int s[20];
int a[55],b[55],c[55],d[55];
int sum = -inf;
int n,m,q;

void check(){
	int no = 0;
	for(int i=0;i<q;i++){
		if(s[b[i]] - s[a[i]] == c[i]){
			no += d[i];
		}
	}
	sum = max(sum,no);
	return;
}


void dfs(int now,int val){
	s[now] = val;
	if(now == n){
		check();
		return;
	}
	for(int i=val;i<=m;i++){
		dfs(now+1,i);
	}
}


int main(){
	cin>>n>>m>>q;
	for(int i=0;i<q;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	dfs(1,1);
	cout<<sum<<endl;
	return 0;
} 
