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
	int n;
	long double ans=0;
	cin >> n;
	vector<double> a(n);
	rep(i, n) {
		cin >> a.at(i);
		a.at(i) = 1 / a.at(i);
	}
	rep(i, n) {
		ans += a.at(i);
	}
	cout << 1 / ans << endl;
	return 0;
}