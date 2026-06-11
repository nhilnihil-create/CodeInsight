#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[111][3];
	cin>>n;
	cin>>a[1][1]>>a[1][2]>>a[2][1]>>a[2][2];
	for(int i=3;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
		if(a[i][1]==a[i][2]&&a[i-1][1]==a[i-1][2]&&a[i-2][2]==a[i-2][1]){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}