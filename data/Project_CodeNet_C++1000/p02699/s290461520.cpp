#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {

	int s, w;

	cin >> s >> w;

	if (w >= s) {
		cout << "unsafe" << endl;
	}
	else {
		cout << "safe" << endl;
	}

	return 0;
}