#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include<cstdio>
#include <vector>
#include<queue>
#include<limits.h>
#include<string.h>
#include<functional>
using namespace std;

signed main() {
	int a, b; 
	while (cin >> a >> b, a | b) {
		for (int c = 0; c < a; c++) {
			for (int d = 0; d < b; d++) {
				if (c == 0 || c == a - 1 || d == 0 || d == b - 1) {
					cout << '#';
				}
				else cout << '.';
			}
			cout << endl;
		}
		puts("");
	}
}