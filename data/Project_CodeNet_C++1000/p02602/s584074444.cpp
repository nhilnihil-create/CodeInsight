// AUTHOR: ROSHAN SRIVASTAVA
// WEBSITE: https://www.youtube.com/channel/UC6uQdd7kLLOdlHSVklhV7Cw

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n, k; 


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin>>n>>k;
	vector<int> arr(n + 1);

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
		if(i < k) continue;
		else if (arr[i] > arr[i - k]) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}