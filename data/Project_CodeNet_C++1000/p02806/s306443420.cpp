#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
using namespace std;
int main(){
	int n, t[100], ans = 0;
	string s[100], x;
	cin >> n;
	for (int a = 0; a < n; a++) {
		cin >> s[a] >> t[a];
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (s[i] == x) {
			for (int j = i+1; j < n; j++) {
				ans += t[j];
			}
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

