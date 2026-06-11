#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	string s;
	cin >>s;
	int l = s.size();

	if (l%2==1) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < l/2;i++) {
		if (s[i*2]!= 'h' || s[i * 2+1] != 'i') {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;


	return 0;
}