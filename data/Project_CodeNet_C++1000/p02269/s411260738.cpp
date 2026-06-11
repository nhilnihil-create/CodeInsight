#include<iostream>
 #include <string.h>
using namespace std;
int table[16777216];
char str[13];

int get_num(char c) {
	switch (c)
	{
		case 'A': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default: return 4;
	}
}

int hash_table() {
	int ret=0;
	for (int i = 0; str[i] != '\0'; i++) {
		ret = ret * 4 + get_num(str[i]);
	}
	return ret;
}

int main() {
	int n;
	char com[6];
	cin >> n;
	memset(table, 0, sizeof(table));
	for (int i = 0; i < n; i++) {
		cin >> com >> str;
		if (com[0] == 'i') {
			table[hash_table()] = 1;
		}
		else {
			int ret = hash_table();
			if (table[ret] == 1)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}