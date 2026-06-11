// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	int n;
	cin>>n;
	int arr[n];
	int brr[n];
	int crr[n];
	for (int i = 0; i < n; i++){
		cin>>arr[i];
		--arr[i];
	}
	for (int i = 0; i < n; i++){
		cin>>brr[i];
	}
	for (int i = 0; i < n-1; i++){
		cin>>crr[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += brr[arr[i]];
	}
	for (int i = 0; i <n ; ++i){
		if (i > 0 && arr[i] == arr[i-1]+1) {
			 sum += crr[arr[i-1]];
		}
	}
	cout<<sum<<endl;

}