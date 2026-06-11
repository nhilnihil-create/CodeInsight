#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int a;
	string s;
	cin >> a >> s;

	if (a >= 3200) {
		cout << s << endl;
	}
	else {
		cout << "red" << endl;
	}

	return 0;
}

