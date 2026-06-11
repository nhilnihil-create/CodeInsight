#include<bits/stdc++.h>
using namespace std;
int main(){
	long long ret = 0;
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int index = (lower_bound(arr.begin(),arr.end(),arr[i]+arr[j])-arr.begin());
			ret+=index-(j+1);
		}
	}
	cout<<ret;
}