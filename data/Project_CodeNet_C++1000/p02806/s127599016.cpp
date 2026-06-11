#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n;
	string name[55];
	int time[55];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name[i];
		cin >> time[i];
	}

	string x;
	cin >> x;

	int spot;
	for (int i = 0; i < n; i++) {
		if (name[i] == x) {
			spot = i;
			break;
		}
	}

	int result = 0;
	for (int i = spot + 1; i < n; i++) {
		result += time[i];
	}

	cout << result << "\n";

	return 0;
}

