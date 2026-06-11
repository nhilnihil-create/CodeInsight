#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
long long cut(int x){
	long long ret = 0;
	for(int i=0; i<arr.size(); i++){
		if(arr[i]>x){
			ret+=arr[i]/x;
			if(arr[i]%x==0) ret--;
		}
	}
	return ret;
}
int main(){
	int n,k;
	cin>>n>>k;
	arr = vector<int>(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int start = 1;
	int fin = *max_element(arr.begin(),arr.end());
	while(start<=fin){
		int mid = (start+fin)/2;
		if(cut(mid)<=k) fin = mid-1;
		else start = mid+1;
	}
	cout<<start;
}