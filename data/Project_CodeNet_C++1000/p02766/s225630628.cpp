#include "bits/stdc++.h"

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int ans = 1;
	int tmp = K;
	while (tmp <= N) {
		++ans;
		tmp *= K;
	}
	cout << ans <<endl;
	return 0;
}