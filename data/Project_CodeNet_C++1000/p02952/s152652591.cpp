#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 0;
	for(int i = 1; i <= n; ++i) {
		string s = to_string(i);
		answer += s.size() % 2;
	}
	cout << answer;
}
