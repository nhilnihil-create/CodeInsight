#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	string s;
	string front = "";

	cin >> s;
	int q;
	cin >> q;
	int re = 0;

	for (int i = 0;i < q;i++) {
		int t;
		cin >> t;
		if (t == 1) {
			re++;
		}
		else {
			int f;
			string c;
			cin >> f >> c;
			if (re % 2 == 0) {
				if (f == 1) {
					front += c;
				}
				else {
					s.append(c);
				}
			}
			else
			{
				if (f == 1) {
					s.append(c);
				}
				else {
					front += c;
				}
			}
		}
	}
	reverse(front.begin(), front.end());
	s = front + s;

	if (re % 2 == 1) {
		reverse(s.begin(), s.end());
	}

	cout << s << endl;
	return 0;
}