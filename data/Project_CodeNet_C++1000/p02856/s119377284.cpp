#include "bits/stdc++.h"
using namespace std;

int main() {
	long long M;
	long long COUNT = 0, DIGIT = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		long long D, C;
		cin >> D >> C;
		COUNT += D * C;
		DIGIT += C;
	}
	long long ANS = 0;
	if (COUNT % 9 == 0) ANS = COUNT / 9 - 1;
	else ANS = COUNT / 9;
	cout << ANS + DIGIT - 1 << endl;
}