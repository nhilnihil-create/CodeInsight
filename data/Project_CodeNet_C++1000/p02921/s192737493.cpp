#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	rep(i, 3) {
		if (s1[i] == s2[i]) {
			ans++;
		}
	}
	cout << ans << endl;
}
