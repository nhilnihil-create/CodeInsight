#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	string S, T;
	cin >> S >> T;

	T.pop_back();

	if (S == T) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

}