#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < n - 2; ++i) {
		string cur = s.substr(i, 3);
		cnt += cur == "ABC";
	}
	cout << cnt;
}
