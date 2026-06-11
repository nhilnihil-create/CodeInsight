#include<iostream>
using namespace std;

int main() {
	for (int i = 0; i < 81; i++) {
		cout << i / 9 + 1 << "x" << i % 9 + 1 << "=" << ((i / 9) + 1)*((i % 9) + 1) << "\n";
	}
	return 0;
}
