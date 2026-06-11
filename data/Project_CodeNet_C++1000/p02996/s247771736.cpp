#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int main(){
	int n;
	cin>>n;
	vector<pi>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i].second>>arr[i].first;
	sort(arr.begin(),arr.end());
	ll curr = 0;
	for(int i=0; i<n; i++){
		curr+=arr[i].second;
		if(curr>arr[i].first){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}