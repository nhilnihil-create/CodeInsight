#include <iostream>
using namespace std;
int main() {
	int N, D;
	cin >> N >> D;
	int R = 2 * D + 1;
	cout << (N + R - 1) / R << endl;
	return 0;
}