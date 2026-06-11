#include <bits/stdc++.h>
using namespace std;
long long N, M, k;
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> k;
	vector< long long > a(N + 3, 0LL), b(M + 3, 0LL);
	// a[0] = b[0] = 0;
	for (int i = 0; i < N; ++i){
		cin >> a[i];
		if(i)
			a[i] = a[i] + a[i-1];
		// a[i] += a[i-1];
	}
	for (int j = 0; j < M; ++j){
		cin >> b[j];
		if(j)
			b[j] += b[j-1];
	}

	long long ans = 0, j = M-1;

	for (int i = 0; i < N; ++i) {
		if(a[i] > k)
			break;
		while(j >= 0 && b[j] +a[i]> k)
			--j;
		//if(j>=0)
			ans = max(i+j+2, ans);
	}

	j = N - 1;
	for (int i = 0; i < M; ++i) {
		if(b[i] > k)
			break;
		while(j >= 0 && a[j] +b[i]> k)
			--j;
		//if(j >= 0)
			ans = max(i+j+2, ans);
	}


	// /for (int i = 1; i )
	cout << ans << '\n';
	return 0;
}