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
	int k, n,i=0,ans=0,kaka=1000000;
	cin >> k >> n;
	vector<int>a(n),m(n,0);
	rep(i, n) {
		cin >> a.at(i);
	}
	rep(i, n-1) {
		m.at(i) = a.at(i + 1) - a.at(i);
	}
	m.at(n - 1) = k - a.at(n-1) + a.at(0);

	sort(m.begin(), m.end());
	reverse(m.begin(), m.end());
	rep(i, n) {
		ans += m.at(i);
	}
	cout << ans - m.at(0)  << endl;
	return 0;
}
