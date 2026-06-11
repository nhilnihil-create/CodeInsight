#include <iostream>
#include <vector>
#include <string>

using namespace  std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	long long int A, B;
	cin >> A >> B;
	if (A > B) {
		cout << A * B / gcd(A, B) << endl;
	}
	else {
		cout << A * B / gcd(B, A) << endl;
	}
	return 0;
}