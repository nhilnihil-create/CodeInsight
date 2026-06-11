// AUTHOR: ROSHAN SRIVASTAVA
// WEBSITE: https://www.youtube.com/channel/UC6uQdd7kLLOdlHSVklhV7Cw

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n; 

ll arr[89];

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin>>n;

	for(int i = 0; i < n; i++)
		cin>>arr[i];

	ll s = 0;
	ll m = 1000;
	for(int i = 0; i < n; i++) {
		if(arr[i + 1] > arr[i]) {
			s = m / arr[i];
			m += (arr[i + 1] - arr[i]) * s;
		}
	}
	cout<<m<<endl;

	return 0;
}