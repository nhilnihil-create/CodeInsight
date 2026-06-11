#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
const int num1 = 1046527;
const int num2 = 13;
char c[num1][num2];
inline int getInt(char ch) {
	if (ch == 'A') return 1;
	else if (ch == 'C') return 2;
	else if (ch == 'G') return 3;
	else if (ch == 'T') return 4;
	return 0;
}
inline int getKey(char str[]) {
	int p = 1, sum = 0;
	for (int i = 0; i < strlen(str); i++) {
		sum += p*getInt(str[i]);
		p *= 5;
	}
	return sum;
}
int h1(int key) { return key % num1; }
int h2(int key) { return 1 + key % (num1 - 1); }
inline int insert(char str[]) {
	int i, key = getKey(str);
	for (i = 0; ; i++) {
		int h = (h1(key) + i*h2(key)) % num1;
		if (strcmp(c[h], str) == 0) return 1;//?????´??????return 0
		else if (strlen(c[h]) == 0) {
			strcpy(c[h], str);
			return 0;
		}
	}
	return 0;
}
inline int find(char str[]) {
	int i;
	int sum = 0, key = getKey(str);
	for (i = 0; ; i++) {
		int h = (h1(key) + i*h2(key)) % num1;
		if (strcmp(c[h], str) == 0) return 1;
		else if (strlen(c[h]) == 0) return 0;
	}
	return 0;
}
int main() {
	int n;
	char com[9], str[num2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> com >> str;
		if (com[0] == 'i')
			insert(str);
		else {
			if (find(str))
				cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}