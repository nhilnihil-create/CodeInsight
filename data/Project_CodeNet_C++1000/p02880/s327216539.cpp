#include <iostream>
using namespace std;
void sol(int N) {
	for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			if (i*j==N) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
	return;
}
int main () {
	int N;
	cin >> N;
	sol(N);
}