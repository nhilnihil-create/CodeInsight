#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int x, y;
	cin >> x >> y;
	if (y % 2 != 0) {
		cout << "No" << endl;
		return 0;
	}
	if (x * 4 < y||y/2<x) {
		cout << "No" << endl;
		return 0;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}