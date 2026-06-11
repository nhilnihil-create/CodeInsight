#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> x(5);
	
	for (int i = 0; i < 5; i++) {
		cin >> x.at(i);
		if (x.at(i) != i + 1) {
			cout << i + 1 << endl;
		}
	}
	
}