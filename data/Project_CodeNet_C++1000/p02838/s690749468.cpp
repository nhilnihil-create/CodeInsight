#include<bits/stdc++.h>
using namespace std;	
long long moder = 1000000007;
long long total_zero[61];
long long total_one[61];
long long unit = 1;
long long counter[61];

int main(){
	int n;
	cin>>n;
	vector<long long>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	
	for(int i=0; i<n; i++){
		for(long long j=0; j<=60; j++){
			if((unit<<j)&arr[i]) total_one[j]++;
			else total_zero[j]++;
		}
	}
	for(int j=0; j<=60; j++){
		counter[j] = total_zero[j]*total_one[j];
	}
	long long ret = 0;
	for(int i=0; i<=60; i++){
		long long curr = (unit<<i);
		curr%=moder;
		curr*=counter[i]%moder;
		ret+=curr%moder;
		ret%=moder;
	}
	cout<<ret;

}