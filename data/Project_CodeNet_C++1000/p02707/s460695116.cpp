#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1]={0};
	for(int i=1;i<n;i++){
		int x;cin>>x;
		a[x]++;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}

	return 0;
}
