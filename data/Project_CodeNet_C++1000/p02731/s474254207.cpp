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
	int l;
	cin >>l;

	double a = double(l) / 3;

	printf("%f",a*a*a);
	return 0;
}