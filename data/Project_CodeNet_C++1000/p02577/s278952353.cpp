#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	cin >> N;
	long long sum = 0;
	for (char n : N) {
		sum += static_cast<long long>(n - '0');
	}
	if (sum % 9 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}