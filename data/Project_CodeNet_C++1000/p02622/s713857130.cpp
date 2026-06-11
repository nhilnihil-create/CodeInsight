#include <iostream>
using namespace std;
int main() {
	string S, T;
	int count = 0;
	cin >> S >> T;

	for (int i = 0; i < S.size(); i++) {
		if (S.at(i) != T.at(i)) {
			count++;
		}
		else {
			continue;
		}
	}
	cout << count << endl;
}