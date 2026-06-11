#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int x;
	cin >> x;
	if (x <= 599) {
		cout << 8;
	}
	else if (x <= 799) {
		cout << 7;
	}
	else if (x <= 999) {
		cout << 6;
	}
	else if (x <= 1199) {
		cout << 5;
	}
	else if (x <= 1399) {
		cout << 4;
	}
	else if (x <= 1599) {
		cout << 3;

	}
	else if (x <= 1799) {
		cout << 2;
	}
	else {
		cout << 1;
	}
	return 0;
	return 0;
}