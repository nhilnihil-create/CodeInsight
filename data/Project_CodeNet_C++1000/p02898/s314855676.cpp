#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	vector<int>::iterator it = lower_bound(arr.begin(),arr.end(),k);
	cout<<n-(int)(it-arr.begin());
}
