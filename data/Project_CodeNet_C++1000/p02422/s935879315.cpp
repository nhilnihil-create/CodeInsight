#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

typedef long long ll;

string beautify(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		if ('a' <= c && c <= 'z') ret += c;
		else if ('A' <= c && c <= 'Z') ret += (char)(c-'A'+'a');
	}
	return ret;
}

int main() {
	string str; cin >> str;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string op; cin >> op;
		int a, b; cin >> a >> b;
		if (op == "print") {
			cout << str.substr(a, b-a+1) << endl;
		}
		else if (op == "reverse") {
			reverse(str.begin()+a, str.begin()+b+1);
		}
		else if (op == "replace") {
			string p; cin >> p;
			str = str.substr(0, a) + p + str.substr(b+1);
		}
	}
}