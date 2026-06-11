#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	ll ans=1000;
	for(int i=0; i<n-1; i++){
		if(arr[i]<arr[i+1]){
			ll num=ans/arr[i];
			ans=ans%arr[i];
			ans+=num*arr[i+1];
		}
	}
	cout<<ans;
	return 0;
}