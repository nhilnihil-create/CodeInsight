#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
	for(int i=1;i<=k;i++){
		int d,x;
		cin>>d;
		for(int j=1;j<=d;j++){
			cin>>x;
			a[x]=1;
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) s++;  
	}
	cout<<s<<'\n';
	return 0; 
}