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
#include<queue>
#include<bitset>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);

	for (int i = 0; i < N; ++i) {
		cin >> A.at(i);
	}

	bool ans = true;

	for (int i = 0; i < N; ++i) {
		if (A.at(i) % 2 == 0) {
			if (!(A.at(i) % 3 == 0 || A.at(i) % 5 == 0)) {
				ans = false;
				break;
			}
		}
	}

	if (ans) {
		cout << "APPROVED" << endl;
	}
	else cout << "DENIED" << endl;

}