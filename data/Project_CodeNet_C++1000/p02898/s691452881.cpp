#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,h[100001],cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>h[i];
		if(h[i]>=k) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
} 
