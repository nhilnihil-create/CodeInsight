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
	int i = 0,n, h = 0, p, ans = 0;
	double d ;
	cin >> n;
	vector<int>x(n);
	rep(i, n) {
		cin >> x.at(i);
		h += x.at(i);
	}
	p = h / n;
	if ((h % n *10)/n> 4) {
		p++;
	}
	rep(i, n) {
		d = (double)p - (double)x.at(i);
		ans += (int)d * (int)d;
	}
	cout << ans << endl;

	return 0;
}



