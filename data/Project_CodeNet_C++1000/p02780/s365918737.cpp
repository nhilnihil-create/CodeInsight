#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	int n, k;
	cin >> n >> k;
	vector<int> a(n+1);
	int j;
	
	for (int i = 1; i <= n; i++){
		cin >> j;
		a[i] += a[i - 1] + j + 1;
		//cout << a[i] << endl;
	}

	long double ans = -1, b;

	for (int i = k; i <= n; i++) {
		b = a[i] - a[i - k];
		ans = max(ans, b);
	}

	printf("%.15Lf\n", ans/2);





	return 0;
}
