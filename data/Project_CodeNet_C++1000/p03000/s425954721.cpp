#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,x; cin>>n>>x;
	int arr[n], ans=1;
	cin>>arr[0];
	for(int i=1; i<n; i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	for (int i = 0; i<n; i++){
		if(arr[i]<=x)ans++;
	}
	cout<<ans<<endl;
}
