#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i = 0;i < (n); ++i)

int main() {
	ll n, k;
	cin >> n >> k;
	ll count = 1;
	ll x = n;
	if (n == k) {
		cout << 2 << endl;
		return 0;
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
		while(true) {
		
		x /= k;
		count++;
		if (x < k)break;

	}
	cout << count << endl;
	return 0;
}