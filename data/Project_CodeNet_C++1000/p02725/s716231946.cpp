#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,n;
	cin>>k>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int total = k;
	int mn = total;
	for(int i=1; i<n; i++){
		mn = min(mn,total-(arr[i]-arr[i-1]));
	}
	mn = min(mn,total-(k-arr[n-1])-arr[0]);
	cout<<mn;
}