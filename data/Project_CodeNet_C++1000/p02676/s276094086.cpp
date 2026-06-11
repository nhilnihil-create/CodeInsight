#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {

	int k;
	string s;

	cin >> k >> s;

	if (k >= s.length()) {

		cout << s;

	}
	else {

		for (int i = 0; i < k; i++) {

			cout << s[i];

		}

		cout << "...";

	}

	

}