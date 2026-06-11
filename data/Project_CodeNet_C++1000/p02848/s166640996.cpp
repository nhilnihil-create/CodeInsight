#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(char c : s) {
		int cur = c - 'A';
		cur += n;
		cur %= 26;
		cout << char('A' + cur);
	}
}
