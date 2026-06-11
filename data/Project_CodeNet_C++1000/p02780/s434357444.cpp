#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	double arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		arr[i]++;
		arr[i]/=2.0;
	}
	double curr = 0;
	for(int i=0; i<k; i++) curr+=arr[i];
	double mx = curr;
	for(int i=k; i<n; i++){
		curr+=arr[i];
		curr-=arr[i-k];
		mx = max(mx,curr);
	}
	cout.precision(7);
	cout<<mx;
}