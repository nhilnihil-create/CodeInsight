#include <iostream>
#include <string>
using namespace std;

int main() {
	int a;
	string s;
	cin >> a >> s;
	string ans = "red";
	if (3200 <= a) {
		ans = s;
	}
	cout << ans << endl;
	return 0;
}
