#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int M; cin >> M;
	if (M >= 400 && M <= 599)cout << 8 << endl;
	if (M >= 600 && M <= 799)cout << 7 << endl;
	if (M >= 800 && M <= 999)cout << 6 << endl;
	if (M >= 1000 && M <= 1199)cout << 5 << endl;
	if (M >= 1200 && M <= 1399)cout << 4 << endl;
	if (M >= 1400 && M <= 1599)cout << 3 << endl;
	if (M >= 1600 && M <= 1799)cout << 2 << endl;
	if (M >= 1800 && M <= 1999)cout << 1 << endl;
}