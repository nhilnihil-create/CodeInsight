#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[10][10][11]={0};
	for(int i=0;i<n;i++){
		int b,f,r,v;
		cin>>b>>f>>r>>v;
		a[b][f][r]+=v;
		if(a[b][f][r]<0) a[b][f][r]=0;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=10;k++){
				cout<<" "<<a[i][j][k];
			}
			cout<<"\n";
		}
		if(i!=4){ 
			for(int j=0;j<20;j++) cout<<"#";
			cout<<"\n";
		}
	}
	return 0;
}