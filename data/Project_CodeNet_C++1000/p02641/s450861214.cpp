#include<bits/stdc++.h>
using namespace std;
int vis[105];
int main(){
	int x,n;
	cin>>x>>n;
	if(n==0){
		cout<<x;
		return 0;
	}
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		vis[num[i]]=1;
	}
	int step=0;
	while(1){
		if(!vis[x-step]){
			cout<<x-step;
			break;
		}
		if(!vis[x+step]){
			cout<<x+step;
			break;
		}
		step++;
	}
	return 0;
}