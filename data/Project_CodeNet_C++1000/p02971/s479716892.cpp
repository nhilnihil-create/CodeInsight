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
	int n;
	cin >> n;
	vector<int>a(n),b(n);
	rep(i, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a.rbegin(), a.rend());
	int m1 = a[0];
	int m2 = a[1];
	rep(i, n) {
		int k = b[i];
		if (k == m1) {
			cout << m2;
		}
		else {
			cout << m1;
		}
		cout << endl;
	}
	return 0;
}