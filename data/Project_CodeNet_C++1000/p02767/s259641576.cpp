#include<bits/stdc++.h>
using namespace std;
int sqr(int n){
	return n*n;
}
int main(){
	int n;
	cin>>n;
	int total = 0;
	vector<int>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		total+=arr[i];
	}
	int ret1 = 0;
	int meeting = total/n;
	for(int i=0; i<n; i++) ret1+=sqr(meeting-arr[i]);
	int ret2 = 0;
	meeting++;
	for(int i=0; i<n; i++) ret2+=sqr(meeting-arr[i]);
	cout<<min(ret1,ret2);
}