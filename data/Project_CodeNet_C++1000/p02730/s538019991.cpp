#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string getString() {
	string x;
	cin >> x;
	if (x.size() < 3 || x.size() > 99) {
		return getString();
	}
	if (x.size() % 2 == 0) {
		return getString();
	}
	int tama = static_cast<int>(x.size());
	for (int i = 0; i < tama; i++) {
		if (x[i] < 96 || x[i]>122) {
			return getString();
		}
	}

	return x;
}

bool check_palindrome(string caso) {
	int tama = static_cast<int>(caso.size());
	int ptr1=0;
	int ptr2 = tama - 1;
	for (int i = 0; i < tama / 2; i++) {
		if (ptr1 == ptr2) {
			return true;
		}
		if (caso[ptr1] != caso[ptr2]) {
			return false;
		}
		ptr1++;
		ptr2--;
	}
	

	return true;
}

int main() {
	string caso{ getString() };
	int tama = static_cast<int>(caso.size());
	if (check_palindrome(caso)) {
		int first_case{ ((tama - 1) / 2) };
		string caso1{ caso[0] };
		for (int i = 1; i < first_case; i++)
		{
			caso1 += caso[i];
		}
		if (check_palindrome(caso1)) {
			int second_case{ (tama + 3) / 2 };
			string caso2{ caso[second_case - 1] };
			for (int j = second_case; j < caso.size(); j++)
			{
				caso2 += caso[j];
			}
			if (check_palindrome(caso2)) {
				cout << "Yes";
				return 0;
			}
			cout << "No";
			return 0;
		}
		cout << "No";
		return 0;
	}
	else {
		cout << "No";
	}


	return 0;
}