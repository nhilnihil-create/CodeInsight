#include<bits/stdc++.h>
using namespace std;
vector<int>arr;

int binary_search(int start,int fin,int limit){
	int temp = fin+1;
	while(start<=fin){
		int mid = (start+fin)/2;
		if(arr[mid]<=limit) start = mid+1;
		else fin = mid-1;
	}
	
	
	return temp - start;
}
int main(){
	int n;
	cin>>n;
	arr = vector<int>(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	int ret = 0;
	for(int i=arr.size()-1; i>=2; i--){
		for(int j=i-1; j>=1; j--){
			ret+=binary_search(0,j-1,arr[i]-arr[j]);
		}
	}
	cout<<ret;
}