#include<iostream>
using namespace std;
 
int main() {
	string N;
	cin >> N;
	int rem = 0;
	for (int i = 0; i < N.length(); i++) {
		rem += (N[i] - '0');
		rem = rem % 9;
	}
	if (rem == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
 
}