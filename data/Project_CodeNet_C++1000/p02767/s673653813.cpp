#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, a;
	cin >> n;
	double sum = 0;
	vector<int> arr;
	for(int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
		sum += a;
	}
	sum /= n;
	sum = round(sum);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (arr[i] - sum) * (arr[i] - sum);
	}
	cout << ans;
	return 0;
}