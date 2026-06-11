/*input
3
100 100
10 10000
1 1000000000
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

void run() {
	int i, j, n;
	cin >> n;
	vector<int> a(n), b(n);
	for(i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ret = 0;
	if(n % 2) {
		ret = b[n/2] - a[n/2] + 1;
	}
	else {
		ret = b[n/2] + b[n/2 - 1] - a[n/2] - a[n/2 - 1] + 1;
	}
	cout << ret << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);		
	run();
}
