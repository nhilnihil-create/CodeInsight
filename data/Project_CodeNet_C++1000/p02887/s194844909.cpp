#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;
long long INF = 1LL << 60;
int main() {
	int N;
	string S;
	cin >> N >> S;
	int ans = 1;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i + 1] != S[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}