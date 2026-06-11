#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main() {
	int x, y, s;
	while (cin >> x >> y >> s&&x + y + s != 0) {
		int sum = 0;
		for (int i = 1; i < s; i++) {
			for (int j = 1; j < s; j++) {
				if (i*(100 + x) / 100 + j*(100 + x) / 100 == s) {
					int c = i*(100 + y) / 100;
					int d = j*(100 + y) / 100;
					sum = max(sum, c + d);
				}
			}
		}
		cout << sum << endl;
	}
} 