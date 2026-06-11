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
	ll w,h;
	cin >> h>>w;

	if (h==1 ||w==1) {
		cout << 1;
		return 0;
	}
	
	cout << (w*h+1)/2 << endl;
	

	return 0;
}