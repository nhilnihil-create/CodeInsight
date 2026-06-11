#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;


int main() {
	string s, t;
	cin >> s >> t;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) {
				cout << "No";
				return 0;
			}	
		}

		if (t.size() == s.size() + 1) {
			cout << "Yes";
		}

}