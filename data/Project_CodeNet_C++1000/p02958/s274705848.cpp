#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> b = v;
	sort(v.begin(),v.end());
	int index1 = 0; 
	int index2 = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] != v[i]) {
			if (cnt == 0) {
				index1 = i;
			}else {
				index2 = i;
			}
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << "YES";
	}else if (cnt == 2) {
	    swap(v[index1],v[index2]);
	    if (v == b) {
			cout << "YES";
		}else {
			cout << "NO";
		}
	}else {
		cout << "NO";
	}
}

















