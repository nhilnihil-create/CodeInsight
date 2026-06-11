#include <iostream>
using namespace std;
int main () {
	long long int A, B;
	cin >> A >> B;
	long long int sum=(A*B+1)/2;
	if (A==1 || B==1) {
		cout << "1" << endl;
		return 0;
	}
	cout << sum << endl;
}