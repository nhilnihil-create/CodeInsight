#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string s;
bool is_balanced(int l, int r){
	for(; l < r; ++l) {
		switch(s[l]) {
		case '(':
		case'[':
			goto next;
		case ')':
		case ']':
			return false;
		}
	}

	return true;

next:;

	int cnt = 1;
	for(int i = l + 1; i < r; ++i) {
		switch(s[i]) {
		case '(':
		case'[':
			++cnt;
			break;
		case ')':
		case ']':
			if(--cnt == 0) {
				if(s[l] == '(' && s[i] == ')' || s[l] == '[' && s[i] == ']')
					return is_balanced(l + 1, i) && is_balanced(i + 1, r);
			}
		}
	}

	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(getline(cin, s), s != ".")
		cout << (is_balanced(0, s.size()) ? "yes" : "no") << endl;

	return EXIT_SUCCESS;
}