#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S;
int maxn = 0, cnt = 0;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'R') cnt++;
		else cnt = 0;
		maxn = max(maxn, cnt);
	}
	cout << maxn << endl;
	return 0;
}