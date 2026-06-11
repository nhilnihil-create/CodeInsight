#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ll n;
	cin >> n;
	vector <string> arr (n+1 , "");
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		sort(arr[i].begin(), arr[i].end());
	}
	sort(arr.begin(), arr.end()-1);
	ll ans = 0 , sum = 1;
	for (ll i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1])
			sum++;
		else{
			ans += (sum * (sum-1))/2;
			sum = 1;
		}
	}

	cout << ans << endl;
}
