#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

int ary[SIZE];

string solve(int a, int b, int f) {
	if (f >= 10) return "YES";
	
	if (ary[f] > a) return solve(ary[f], b, f + 1);
	if (ary[f] > b) return solve(a, ary[f], f + 1);

	return "NO";
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i++ < n;) {
		for (int j = 0; j < SIZE; j++) {
			cin >> ary[j];
		}
		cout << solve(0, 0, 0) << endl;
	}
	return 0;
}