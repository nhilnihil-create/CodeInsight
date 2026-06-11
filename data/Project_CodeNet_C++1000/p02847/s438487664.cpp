#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string S;
	vector<string> W = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	cin >> S;
	
	for (int i = 0; i < W.size(); ++i) {
		if (S == W[i]) {
			cout << 7 - i << endl;
			return 0;
		}
	}
	return 0;
}

