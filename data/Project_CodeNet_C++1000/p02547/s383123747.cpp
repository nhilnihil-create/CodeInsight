#include<iostream>
using namespace std;

int main() {
	int n;
	int d[110][2] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i][0] >> d[i][1];
	}
	int count = 0;
	for (int j = 0; j < n; j++) {
		if (count == 3) break;

		if (d[j][0] == d[j][1]) ++count; 
		else if (d[j][0] != d[j][1]) count = 0;
	}
	cout << (count == 3 ? "Yes" : "No") << endl;

	return 0;
}
