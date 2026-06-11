#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,k,ans=0;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>=k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}