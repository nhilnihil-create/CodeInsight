#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;

int main() {

	ll n;
	cin >> n;

	vector<ll> a(n);
	vector<ll> mr(n);

	ll A1 = 0;
	ll A2 = 0;

	rep(i, n) {
		cin >> a[i];
		A1 += a[i];
		if (i % 2 == 1)A2 += a[i];
	}
	mr[0] = A1 - A2 * 2;
	rep(i, n) {

		if (i > 0) {
			mr[i] = 2 * a[i - 1] - mr[i - 1];
		}
	
		if (i != n - 1)cout << mr[i] << " ";
		else cout << mr[i] << endl;
	
	}
	return 0;
}