#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	string a;

	cin >> a;

	int b= a.size();

	for (int i = 0; i < b;i++) {
		if (a[i]=='?') {
			a[i] = 'D';
		}
	}

	cout << a<<endl;

	return 0;
}