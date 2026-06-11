#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	int N;
	string S;
	cin >> N >> S;

	for (int i = 0; i < S.size(); ++i) {
		int index = S[i] - 'A' + N;
		index %= 26;
		S[i] = 'A' + index;
	}

	cout << S << endl;
	return 0;
}
