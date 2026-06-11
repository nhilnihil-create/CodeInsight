#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
	int money;
	int a[15];
}book[15];
int b[15];

int main(){
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<n;i++){
		cin>>book[i].money;
		for(int j=0;j<m;j++) cin>>book[i].a[j];
	}
	int ans=1e7;
	for(int i=0;i<(1<<n);i++){
		memset(b,0,sizeof b);
		int sum=0;
		for(int j=0;j<n;j++)
			if(i>>j&1){
				sum+=book[j].money;
				for(int k=0;k<m;k++) b[k]+=book[j].a[k];
			}
		bool flag=1;
		for(int j=0;j<m;j++) if(b[j]<x) flag=0;
		if(flag) ans=min(ans,sum);
	}
	if(ans==1e7) cout<<"-1";
	else cout<<ans;
	return 0;
}