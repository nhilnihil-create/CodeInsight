#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	float tot = 0;
	for (int i = 0; i<n; i++){
		cin>>arr[i];
		tot+=arr[i];
	}
	tot/=(4*m);
	sort(arr, arr+n, greater<int>());
	for (int i = 0; i<n; i++){
		if (arr[i] < tot){
			if (i >= m){
				cout<<"Yes";
				return 0;
			}
			else{
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
	return 0;
}