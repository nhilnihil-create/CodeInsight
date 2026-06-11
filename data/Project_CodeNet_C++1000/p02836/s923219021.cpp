#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int answer = 0;
	int n = s.size();
	for(int i = 0; i < n - i - 1; ++i)
		answer += s[i] != s[n - i - 1];
	cout << answer;
}
