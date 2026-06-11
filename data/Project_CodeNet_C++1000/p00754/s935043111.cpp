#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
	string str;
	while (getline(cin, str), str != ".") {
		bool hasBalance = true;
		stack<int> sKako;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				sKako.push(1);
			}else if (str[i] == ')') {
				if (sKako.empty()) {
					hasBalance = false;
					break;
				}
				if (sKako.top() != 1) {
					hasBalance = false;
					break;
				}
				sKako.pop();
			}else if( str[i] == '[') {
				sKako.push(2);
			}else if (str[i] == ']') {
				if (sKako.empty()) {
					hasBalance = false;
					break;
				}
				if (sKako.top() != 2) {
					hasBalance = false;
					break;
				}
				sKako.pop();
			}
		}
		if (!sKako.empty()) {
			hasBalance = false;
		}

		cout << (hasBalance ? "yes" : "no") << endl;
	}

	return 0;
}