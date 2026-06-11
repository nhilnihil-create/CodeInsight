#include<iostream>


using namespace std;

int main() {
	string S;
	cin >> S;
	
	string s = "";

	for (int i = 0; i < S.length() / 2; i++) {
		s += "hi";
		if (S == s) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;


}