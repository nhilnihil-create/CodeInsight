#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	cin >> n;
	int total = 0;
	vector<int> vec(n);
	vector<int> party(3);
	for (int i = 0; i < n; i++) {
		cin >> p;
		vec.at(i) = p;
	}
	for (int j = 0; j < n - 2; j++) {
		vector<int> party(3);
		party.at(0) = vec.at(j);
		party.at(1) = vec.at(j + 1);
		party.at(2) = vec.at(j + 2);
		if (party.at(0) < party.at(1) && party.at(1) < party.at(2)) {
			total++;
		}
		else if (party.at(0) > party.at(1) && party.at(1) > party.at(2)) {
			total++;
		}
		else {
			continue;
		}
	}
	cout << total << endl;
}