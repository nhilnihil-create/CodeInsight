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

// 特定の文字列を数える関数
size_t count(const string& str, const string& sub, const size_t ini = 0, const size_t fin = string::npos) {
	size_t pos = str.find(sub, ini);
	size_t cnt = 0;
	while (pos < fin) {
		cnt += 1;
		pos = str.find(sub, pos + sub.length());
	}
	return cnt;
}

int main() {

	int N;
	int A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	A--;
	B--;
	C--;
	D--;

	string S;
	cin >> S;

	int c1, c2;
	bool jdg = false;

	if (C < D) {
		c1 = count(S, "##", A, C);
		c2 = count(S, "##", B, D);
		if (c1 == 0 && c2 == 0) {
			jdg = true;
		}
	}
	else {
		int c3;
		c1 = count(S, "##", A, C);
		c2 = count(S, "##", B, D);
		c3 = count(S, "...", B - 1, D);
		if (c1 == 0 && c2 == 0 && c3 > 0) {
			jdg = true;
		}
	}

	if (jdg == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}