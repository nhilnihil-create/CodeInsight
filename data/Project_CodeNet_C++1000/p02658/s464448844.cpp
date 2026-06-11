#include<bits/stdc++.h>
#include<vector>

const long long MAX = 1e18;
using namespace std;  
int main() {

	int N;
	cin >> N;
	vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		if (a[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	long long mul = 1;
	for (int i = 0; i < N; i++) {
		if (mul > MAX / a[i]) {
			cout << -1 << endl;
			return 0;
		}
		else 
                     mul *= a[i];
	}
	
	cout << mul << endl;
	return 0;
}
