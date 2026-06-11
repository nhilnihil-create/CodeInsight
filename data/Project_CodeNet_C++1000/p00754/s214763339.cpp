#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string a;
	while (getline(cin,a),a!=".") {
		vector<int>s;
		for (int b = 0; b < a.length(); b++) {
			if (a[b] == '(' || a[b] == '[') { s.push_back(a[b]); }
			else if (a[b] == ')') {
				if (s.size() == 0 || s[s.size() - 1] !='(') { goto l; }
				s.pop_back();
			}
			else if (a[b] == ']') {
				if (s.size() == 0 || s[s.size() - 1] != '[') { goto l; }
				s.pop_back();
			}
		}
		if (s.size() != 0)goto l;
		cout << "yes" << endl;
		goto r;
	l:;
		cout << "no" << endl;
	r:;
	}
}