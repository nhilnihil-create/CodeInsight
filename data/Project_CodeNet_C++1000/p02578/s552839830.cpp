#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int answer=0;
	for(int i=1;i<n;i++){
		if(arr[i]<arr[i-1]){
			answer+=arr[i-1]-arr[i];
			arr[i]=arr[i-1];
		}
	}
	cout << answer << endl;
	return 0;
}