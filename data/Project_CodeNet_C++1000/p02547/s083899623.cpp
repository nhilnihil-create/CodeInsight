#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,a[1001],b[1001],s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(i=n-1;i>1;i--){
		if(a[i]==b[i]&&a[i-1]==b[i-1]&&a[i-2]==b[i-2]){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}