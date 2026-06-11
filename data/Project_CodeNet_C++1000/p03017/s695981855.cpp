#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
	string S; cin >> S;
	bool z = 1;
	if (C < D) {
		for (int i = A; i < D; i++) {
			if (S[i] == '#'&&S[i - 1] == '#') {
				z = 0; break;
			}
		}
		if (z == 1)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		bool d = 0;
		for (int i = A; i < C; i++) {
			if (S[i] == '#'&&S[i - 1] == '#') {
				z = 0; break;
			}
		}
		for (int i = B - 1; i < D; i++) {
			if (S[i - 1] == S[i] && S[i] == S[i + 1] && S[i] == '.')d = 1;
		}
		if (z == 1 && d == 1)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}



