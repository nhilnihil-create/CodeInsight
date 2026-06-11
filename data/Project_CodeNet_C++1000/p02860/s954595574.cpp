#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string cur = s.substr(0, n / 2);
	cur += s.substr(0, n / 2); 
	cout << (cur == s ? "Yes" : "No");
}
