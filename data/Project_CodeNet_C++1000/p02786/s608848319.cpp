#include<iostream>
using namespace std;
long long int cara(long long int x);
int main() {

	long long int n;
	cin >> n;
	cout << cara(n) << endl;
	return 0;

}
long long int cara(long long int x) {

	int i = 0;
	if (x == 1) {
		return 1;
	}
	else {
		return 1  + 2 * cara((long long int)(x / 2));
	}

}