#include <bits/stdc++.h>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif 

	long long a[2], b[2];

	cin >> a[0] >> a[1] >> b[0] >> b[1];

	long long ans = -1e18+7;

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			ans = max(ans, a[i] * b[j]);
		}
	}

	cout << ans << endl;

	return 0;
}