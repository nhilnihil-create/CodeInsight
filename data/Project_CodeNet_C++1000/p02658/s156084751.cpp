#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	long double prod = 1;
	long long arr[n];
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int i=0; i<n; ++i){
		prod*=arr[i];
		if(prod-1000000000000000000 > 0){
			cout << "-1";
			return 0;
		}
	}
	cout << (long long)prod;
}
