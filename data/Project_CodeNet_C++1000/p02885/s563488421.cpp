#include<iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int size =  2 * B;

	if (size < A) {
		cout << A - size << endl;
	}
	else {
		cout << 0 << endl;
	}

}
	
