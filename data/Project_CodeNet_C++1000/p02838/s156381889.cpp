#include<bits/stdc++.h>
using namespace std;
long long unit = 1;
long long moder = 1000000007;
int main(){
	int n;
	cin>>n;
	long long bit[61]={0};
	for(int i=0; i<n; i++){
		long long num;
		cin>>num;
		for(int j=0; j<=60; j++){
			if((unit<<j)&num) bit[j]++;
		}
	}
	long long ret = 0;
	for(int i=0; i<=60; i++){
		long long total = bit[i]*(n-bit[i]);
		total%=moder;
		long long val = (unit<<i);
		val%=moder;
		ret+=total*val;
		ret%=moder;
	}
	cout<<ret;
}