#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	string s;
	cin >>s;

	int a = s.size();

	for (int i = 0; i < (a - 1) / 2; i++) {
		if (s[i] != s[a-i-1]) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (int i = 0; i < (a - 1) / 4;i++) {
		if (s[i] != s[(a - 1) / 2 -i-1]) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (int i = 0; i < (a - 1) / 4; i++) {
		if (s[i+ ((a - 1) / 2)+1] != s[a-i-1]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes"<< endl;
	return 0;
}