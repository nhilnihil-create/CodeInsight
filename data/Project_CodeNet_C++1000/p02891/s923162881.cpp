#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	string S;
	long long K;
	cin >> S;
	cin >> K;

	long long jdg = 1;
	for (long long i = 0; i < S.length() - 1; i++) {
		if (S[i + 1] == S[i]) {
			jdg += 1;
		}
	}

	long long jdg1 = S.length();

	long long cnt = 0;
	for (long long i = 0; i < S.length() - 1; i++) {
		if (S[i + 1] == S[i]) {
			cnt += 1;
			i++;
		}
	}

	long long dcnt = 0;
	S += S;
	for (long long i = 0; i < S.length() - 1; i++) {
		if (S[i + 1] == S[i]) {
			dcnt += 1;
			i++;
		}
	}

	dcnt = dcnt - 2 * cnt;

	long long ans = K * cnt + (K - 1) * dcnt;


	// ������̑S�Ă����������̂Ƃ������A��O����
	if (jdg == jdg1) {
		ans = K * jdg1 / 2;
	}

	cout << ans << endl;

	return 0;
}