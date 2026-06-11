
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	a--;
	b--;
	c--;
	d--;
	string s;
	cin >> s;

	bool canRace = true;
	for (int i = a;i < c;i++) {
		if (s[i] == '#' && s[i + 1] == '#') {
			canRace = false;
		}
	}

	for (int i = b; i < d;i++) {
		if (s[i] == '#' && s[i + 1] == '#') {
			canRace = false;
		}
	}

	if (d < c) {
		bool canBeyond = false;
		for (int i = b ; i <=d ;i++) {
			if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
				canBeyond = true;
			}
		}

		if (!canBeyond) {
			canRace = false;
		}
	}
	cout << (canRace ? "Yes" : "No") << endl;

}

