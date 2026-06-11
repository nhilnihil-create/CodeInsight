#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	vector<int> bingo(9, 0);
	vector<bool> hit(9, 0);
	for (int i = 0; i < 9; i++) {
		cin >> bingo.at(i);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < 9; j++) {
			if (bingo.at(j) == x) hit.at(j) = true;
		}
	}
	string ans = "No";
	if (hit.at(0)) {
		if (hit.at(1) && hit.at(2)) ans = "Yes";
		else if (hit.at(4) && hit.at(8)) ans = "Yes";
		else if (hit.at(3) && hit.at(6)) ans = "Yes";
	}

	if (hit.at(1) && hit.at(4) && hit.at(7)) ans = "Yes";

	if (hit.at(2)) {
		if (hit.at(5) && hit.at(8)) ans = "Yes";
		else if (hit.at(4) && hit.at(6)) ans = "Yes";
	}

	if (hit.at(3) && hit.at(4) && hit.at(5)) ans = "Yes";

	if (hit.at(6) && hit.at(7) && hit.at(8)) ans = "Yes";

	cout << ans << endl;
}