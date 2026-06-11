#include <iostream>
using namespace std;

int main() {
	string s, str;
	cin >> s >> str;
	int cnt = 0;
	for(int i = 0; i < 3; ++i)
		cnt += s[i] == str[i];
	cout << cnt;
}
