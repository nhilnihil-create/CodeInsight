#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;

int main() {
	int N;
	ll X, ans;

	cin >> N;
	vector<ll> a(N);
	
	for (int i = 0; i < N; i++){
		cin >> a[i];
	}

	X = a[0];
	for (int i = 1; i < N; i++){
		X = X^a[i];
	}
	
	for (int i = 0; i < N; i++){
		ans = X^a[i];
		cout << ans << endl;
	}
	return 0;
}