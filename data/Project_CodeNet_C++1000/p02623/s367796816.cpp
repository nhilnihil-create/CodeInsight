#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, k, a[200001], b[200001];
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i)a[i]+=a[i-1];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		if(i)b[i]+=b[i-1];
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		if(a[i] > k)break;
		int j = upper_bound(b , b + m + 1, k - a[i]) - b;
		ans = max(ans, i+j-1);
	}
	cout << ans  << '\n';
}
//asdlk