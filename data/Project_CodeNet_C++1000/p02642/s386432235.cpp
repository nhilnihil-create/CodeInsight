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
	int k = 1000001;
	int n;
	cin >> n;
	vector<int>a(k);
	vector<int>b(n);
	rep(i, n) {
		int x;
		cin >> x;
		b[i] = x;
		if (a[x] != 0) {
			a[x]++;
			continue;
		}
		for (int j = x; j < k; j += x) {
			a[j]++;
		}
	}
	ll ct(0);
	for (int i : b) {
		//cout << i << endl;
		if (a[i]==1) {
			//cout << a[i] << endl;
			++ct;
		}
	}
	cout << ct << endl;
	return 0;
}