#include <iostream>

using namespace std;

const int N = 105;
int main() {
	int n;
	cin >> n;
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x % 2 != 0 && i % 2 != 0)
			counter++;
	}	
	cout << counter << endl;
	return 0;
}