#include<bits/stdc++.h>
using namespace std;
int arr[105];

int main(){
	int n;
	cin>>n;
	for(int i=1; i<n; i++) cin>>arr[i];
	int ret = 0;
	arr[0] = 10000000;
	for(int i=1; i<n; i++){
		ret+=min(arr[i-1],arr[i]);
	}
	cout<<ret+arr[n-1];
}