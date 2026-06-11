#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	string str;
	while ( getline(cin, str), str != "." ) {
		int k = 0, K = 0;
		stack<int> last;
		bool ans = true;
		for (int i = 0; i < str.size(); ++i) {
			switch (str[i]) {
				case '(':
					++k;
					last.push(0);
					break;

				case ')':
					if (last.empty() || last.top() != 0) {
						ans = false;
					}
					else {
						if (--k < 0) ans = false;
						last.pop();
					}
					break;

				case '[':
					++K; last.push(1);
					break;

				case ']':
					if (last.empty() || last.top() != 1) {
						ans = false;
					}
					else {
						if (--K < 0) ans = false;
						last.pop();
					}
					break;
			}
		}
		if (k != 0 || K != 0) ans = false;
		if (ans) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}