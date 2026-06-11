#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <cmath>
#define ll long long

using namespace std;

const double pi = 3.14159265358979323846;

vector<int> g[100005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll A, B, C, K;

	cin >> A >> B >> C >> K;

	if (A >= K) {
		cout << K << endl;
	}
	else {

		ll left = K - A;

		if (B > left) {
			cout << left << endl;
		}
		else {

			ll evenMoreLeft = left - B;
			cout << evenMoreLeft * -1 + 0 + A << endl;
		}
	}

	return 0;
}