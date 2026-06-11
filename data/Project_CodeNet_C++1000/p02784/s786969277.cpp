#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int H, N;
	cin >> H >> N;
	string ans = "No";
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		H -= A;
		if (H <= 0) {
			ans = "Yes";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}