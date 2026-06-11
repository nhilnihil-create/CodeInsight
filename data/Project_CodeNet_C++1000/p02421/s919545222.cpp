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
	int n; cin >> n;
	int A = 0, B = 0;
	for (int i = 0; i < n; ++i) {
		string a, b; cin >> a >> b;
		if (a > b) A += 3;
		else if (a == b) ++A, ++B;
		else B += 3;
	}
	cout << A << " " << B << endl;
}