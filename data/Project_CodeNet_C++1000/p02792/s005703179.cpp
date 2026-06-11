#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;

int mat[10][10];

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		int tmp = i;
		while(tmp >= 10) tmp /= 10;
		mat[i % 10][tmp]++;
	}


	long long ans = 0;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			ans += 1LL * mat[i][j] * mat[j][i];
		}
	}

	printf("%lld\n", ans);
}
