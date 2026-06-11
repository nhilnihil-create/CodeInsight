#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string S;
	cin >> S;
	int ans = 0;

	for (int i = 0; i < S.size(); ++i) {
		ans += S.at(i) - '0';
	}

	if (ans % 9 == 0) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

}