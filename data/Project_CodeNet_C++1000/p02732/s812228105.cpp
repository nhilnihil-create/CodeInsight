#include<bits/stdc++.h>
using namespace std;
long long counter[200005];
long long arr[200005];
long long comb(int index){
	return counter[index]*(counter[index]-1)/2;
}
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		counter[arr[i]]++;
	}
	long long total = 0;
	for(int i=1; i<=n; i++) total+=counter[i]*(counter[i]-1)/2;
	for(int i=0; i<n; i++){
		long long ret = total-comb(arr[i]);
		counter[arr[i]]--;
		ret+=comb(arr[i]);
		counter[arr[i]]++;
		cout<<ret<<'\n';
	}
}