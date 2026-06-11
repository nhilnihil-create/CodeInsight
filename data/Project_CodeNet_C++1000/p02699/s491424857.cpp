#include<iostream>
#include<string>
using namespace std;

int main() {

	int S, W;

	cin >> S >> W;

	if (S > W) {
		cout << "safe" << "\n";
	}
	else {
		cout << "unsafe" << "\n";
	}

}