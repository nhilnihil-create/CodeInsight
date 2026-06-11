#include <bits/stdc++.h>

using namespace std;

int A[1000005];

int main(){
	string str;
	cin >> str;
	int N = str.size();
	for (int i = 0; i < N; i++) {
		A[i] = str[i] - '0';
	}
	int ans = 0;
	int k = -1;
	bool sobra = false;
	for (int i = N - 1; i > 0; i--) {
		if (A[i] < 10 - A[i]) {
			ans += A[i];
		}
		else {
			if ((A[i] == 5) && (A[i - 1] < 5)){
				ans += A[i];
			} else {
				ans += 10 - A[i];
				k = i - 1;
				if (k == 0) sobra = true;
				while (true) {
					if (k == 0) {
						sobra = true;
						break;
					}
					A[k]++;
					if (A[k] == 10) {
						A[k] = 0;
						k--;
					} else {
						break;
					}
				}
			}
		}
	}
	if (sobra) {
		A[0]++;
		if (A[0] == 10) {
			ans++;
			A[0] = 0;
		}
	}
	if (A[0] <= 10 - A[0]) {
		ans += A[0];
	} else {
		ans += 10 - A[0];
		ans++;
	}
	printf("%d\n", ans);
}