#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	while(k-- && arr.size()) arr.pop_back();
	long long total = 0;
	for(int i=0; i<arr.size(); i++) total+=arr[i];
	cout<<total;
}