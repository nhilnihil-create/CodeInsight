#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n,x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if(sum + v[i] > x) {
			cout << i + 1;
			return 0;
		}
		sum += v[i];
	}
	cout << n + 1; 
}

















