#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int arr[10];
	memset(arr,-1,sizeof(arr));
	int mx = 0;
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		if(arr[a]!=-1 && arr[a]!=b){
			cout<<-1;
			return 0;
		}
		arr[a] = b;
		mx = max(mx,a);
	}
	bool exist = false;
	for(int i=1; i<=n; i++){
		if(arr[i]>0) exist = true;
	}
	if(mx>n) cout<<-1;
	if(arr[1]==0){
		if(exist || n>1) cout<<-1;
		else cout<<0;
		return 0;
	}
	else{
		
		if(arr[1]==-1){
			if(n==1) arr[1] = 0;
			else arr[1] = 1;
		}
		for(int i=1; i<=n; i++){
			if(arr[i]==-1) cout<<0;
			else cout<<arr[i];
		}
	}
}