#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string s;
	if (a <= b) {
		for (int i = 0; i < b; i++) s.push_back(a + '0');
	}
	if (a > b) {
		for (int i = 0; i < a; i++) s.push_back(b + '0');
	}
	cout << s << endl;
	return 0;
}