#include<bits/stdc++.h>
using namespace std;
int sqr(int n){
	return n*n;
}
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int ret = 10000000;
	for(int i=1; i<=100; i++){
		int curr = 0;
		for(int j=0; j<n; j++) curr+=sqr(arr[j]-i);
		ret = min(ret,curr);
	}
	cout<<ret;
}