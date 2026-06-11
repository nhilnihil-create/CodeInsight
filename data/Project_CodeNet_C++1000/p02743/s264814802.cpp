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
	ll a,b,c;
	cin >> a>>b>>c;

	if (a+b<c) {
		if (4 * a*b < (c - a - b)*(c - a - b)) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;

	return 0;
}