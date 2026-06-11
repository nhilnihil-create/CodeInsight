#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;

int main() {
	string S; cin >> S;
	int n = S.length();
	int m = (n - 1) / 2;
	int l = m / 2;
	bool ans = true;
	for (int i = 0; i < m; i++) {
		if (S[i] == S[n - i - 1])continue;
		ans = false;
	}

	for (int i = 0; i < l; i++) {
		if (S[i] == S[m - i - 1])continue;
		ans = false;
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}