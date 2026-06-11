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
	ll A,B,C;

	cin >> A >> B >> C;
	
	swap(A,B);

	swap(A,C);

	cout << A<<endl;
	cout << B << endl;
	cout << C << endl;

	return 0;
}