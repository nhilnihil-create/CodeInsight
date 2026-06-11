#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int main(){
	int A, B, m;
	cin >> A >> B >> m;
	vector<int> a(A), b(B), c(m),d(m+1), x(m), y(m);

	for (int i = 0; i < A; i++)cin >> a.at(i);
	for (int i = 0; i < B; i++)cin >> b.at(i);
	for (int i = 0; i < m; i++)cin >> x.at(i) >> y.at(i) >> c.at(i);
	
	for (int i = 1; i < m + 1; i++) {
		d.at(i) = a.at(x.at(i-1)-1) + b.at(y.at(i-1)-1) - c.at(i-1);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	d.at(0) = a.at(0) + b.at(0);
	sort(d.begin(), d.end());
	cout << d.at(0) << endl;
	return 0;
}
