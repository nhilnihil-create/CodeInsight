#include "bits/stdc++.h"
using namespace std;

//44
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> v[i];
	}
	if (n == 2) {
		cout << 2 * v[0];
		return 0;
	}
	//vector<int> v(n);
	vector<int> ans(n);
	bool e = 1;
	int index = n - 2;
	for (int i = 0; i  + 1 < n - 1; ++i) {
		if (v[i] < v[i + 1]) {
			ans[i] = v[i];
			ans[i + 1] = v[i];
			index = i + 1;
			e = 0;
			break;
		}else {
			ans[i] = v[i];
		}
	}
	//map<ll,int> m;
	//if (index != -1) {
	int p = index + 1;
	for (int i = index; i < n - 1; ++i) {
		if(i + 1 < n - 1) {
			v[i] = min(v[i],v[i + 1]);
			ans[p] = v[i];
		}else {
			ans[p] = v[i];
		}
		++p;
	}
	ll sum = 0;
	if (e) {
	    sum += v[n - 2];
	}
	for (int i = 0; i < n; ++i) {
		//cout << ans[i] << " ";
		sum += (1LL * ans[i]);
	}
	cout << sum;
}
