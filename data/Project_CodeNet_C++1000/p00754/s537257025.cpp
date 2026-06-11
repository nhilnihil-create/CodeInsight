#include <bits/stdc++.h>
using namespace std;

enum { OPEN = 1, CLOSE = 2 };
int bracket[128];
char match[128];

string str;
int idx;

char getc() { return idx < str.size() ? str[idx] : '#'; }
void expr() {
	while(bracket[getc()] == OPEN) {
		const char c = getc();
		++idx;
		expr();
		if(match[c] != getc()) throw "parse error!";
		++idx;
	}
}

bool parse() {
	try {
		idx = 0;
		expr();
		return idx == str.size();
	} catch(const char * s) {
		return false;
	}
}

int main() {
	bracket['('] = bracket['['] = OPEN;
	bracket[')'] = bracket[']'] = CLOSE;
	match['('] = ')';
	match['['] = ']';

	const auto rm = [&](char c) { return !bracket[c]; };
	while(getline(cin, str) && str != ".") {
		str.erase(remove_if(begin(str), end(str), rm), end(str));
		cout << (parse() ? "yes" : "no") << endl;
	}

	return EXIT_SUCCESS;
}