#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); 

	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll sum = 0;
	if (a >= k && k > 0){
		sum+=k;
		k = 0;
	} else if (a < k && k > 0) {
		sum+=a;
		k-=a;
	}

	if (b >= k && k > 0){
		k = 0;
	} else if (b < k && k > 0) {
		k-=b;
	}

	if (c >= k && k > 0){
		sum-=k;
		k = 0;
	} else if (c < k && k > 0) {
		sum-=c;
		k-=c;
	}

	cout << sum;





}