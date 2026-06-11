#include<iostream>
#include<iomanip>
#define LL long long
using namespace std;
int main() {
	LL n, m;
	cin >> n >> m;
	cout << fixed;
	setprecision(5);
	cout << n / m << ' ' << n%m << ' ' << (double)n / m << endl;
	return 0;
}