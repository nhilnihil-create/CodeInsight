#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {
	string str; getline(cin, str);
	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		if ('a' <= c && c <= 'z') cout << (char)(c-'a'+'A');
		else if ('A' <= c && c <= 'Z') cout << (char)(c-'A'+'a');
		else cout << c;
	}
	cout << endl;
}