#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	int cnt = 1;
	char now = S[0];
	for (int i = 1; i < S.length(); i++) {
		if (now != S[i]) {
			now = S[i];
			cnt++;
		}
	}
	int final_gnum = min(N - cnt + K * 2, N -1);
	cout << final_gnum << endl;
	return 0;
}