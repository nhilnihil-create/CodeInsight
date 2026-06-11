#include "bits/stdc++.h"
using namespace std;

int main() {
	int N , X;
	cin >> N>>X; 
	int ans = 1;
	int now = 0;
	for (int n = 0; n < N; ++n) {
		int l;
		cin >> l;
		now += l;
		if (now <= X) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}