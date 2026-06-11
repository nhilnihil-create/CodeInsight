#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int N;
	string S;
	cin >> N;
	cin >> S;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') a[i] = 0;
		if (S[i] == 'G') a[i] = 1;
		if (S[i] == 'B') a[i] = 2;
	}
	vector<long long> count(3, 0);
	for (int i = 0; i < N; i++) {
		count[a[i]]++;
	}
	long long ans = count[0] * count[1] * count[2];

	//条件を満たさないもの引く
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < j; i++) {
			int k = j + (j - i);
			if (k < N) {
				//判定
				if (a[i] == a[j]) continue;
				if (a[j] == a[k]) continue;
				if (a[k] == a[i]) continue;
				ans--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}