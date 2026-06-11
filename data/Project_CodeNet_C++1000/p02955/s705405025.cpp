#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	int arr[n];
	int sum=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	for(int i=sum; i>=1; i--){
		if(sum%i!=0){
			continue;
		}
		int b[n];
		for(int j=0; j<n; j++){
			b[j]=arr[j]%i;
		}
		sort(b, b+n);
		int sum2=0;
		for(int j=0; j<n; j++){
			sum2+=b[j];
		}
		int num=sum2/i;
		int val=0;
		for(int j=n-1; j>=n-num; j--){
			val+=b[j];
		}
		int rem=sum2-val;
		if(rem<=k){
			cout<<i;
			return 0;
		}
	}
	return 0;
}