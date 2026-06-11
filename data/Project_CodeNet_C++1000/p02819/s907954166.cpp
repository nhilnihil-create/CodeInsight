#include <iostream>
#include <vector>

using namespace std;

long long factor(long long X) {

	for (long long a = 2; a*a <= X;) {
		if (X%a == 0) {
			X++;
			a = 2;
			continue;
		}
		a++;
	}
	return X;
}

int main() {
	long long X;
	cin >> X;

	long long Y = factor(X);

	cout << Y << endl;

}