#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++) arr.push_back(arr[i]);
	sort(arr.begin(),arr.end());
	reverse(arr.begin(),arr.end());
	arr.erase(arr.begin());
	long long ret = 0;
	for(int i=0; i<n-1; i++) ret+=arr[i];
	cout<<ret;
}