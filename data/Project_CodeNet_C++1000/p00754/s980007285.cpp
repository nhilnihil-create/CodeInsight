#include <cstdio>
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
bool beginC(char c) {
	return (c == '[' || '(' == c);
}
bool endC(char c) {
	return (c == ']' || ')' == c);
}
bool cuple(char l, char r) {
	return (l == '(' && r == ')') || (l == '[' && r == ']');
}
int size;
bool solve(char str[]) {
	deque<char> deq;
	for (int i = 0; i < size; i++) {
		if (beginC(str[i])) {
			deq.push_front(str[i]);
		}
		else if (endC(str[i])) {
			if (deq.empty()) return false;
			char recent = deq.front();
			if (!cuple(recent, str[i])) {
				return false;
			}
			deq.pop_front();
		}
	}
	return deq.size() == 0;
}

int main() {
	char str_c[128];
	while (1) {
		cin.getline(str_c, 128);
		size = strlen(str_c);
		string str(str_c);
		if (str == ".") return 0;
		cout << (solve(str_c) ? "yes" : "no") <<endl;
	}
	return 0;
}