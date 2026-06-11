#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int array[n];
	for(int i=0; i<n; i++){
		cin>>array[i];
	}
	int maxi=0;
	long long sum=0;
	for(int i=0; i<n; i++){
		maxi= max(array[i], maxi);
		int k=maxi;
		sum+=k-array[i];
	}
	cout<<sum;
}