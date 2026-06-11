#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char prev = '$';
	int answer = 0;
	for(char c : s) {
		if(c != prev) {
			prev = c;
			++answer;
		}
	}
	cout << answer;
}
