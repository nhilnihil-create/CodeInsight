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
	int n,m;
	cin >> n >> m;

	int a = n*(n - 1)/2;
	int b=  m* (m - 1) / 2;

	cout << a+b<< endl;
	return 0;
}