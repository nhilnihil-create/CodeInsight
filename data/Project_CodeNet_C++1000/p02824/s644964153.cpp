#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	ll n, m, v, p;
	cin >> n >> m >> v >> p;


	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	
	

	
	int l = -1;
	int r = n;
	int mid = (l + r) / 2;
	while (mid != l) {
		ll sum = (p - 1 + mid) * m;
		

		
		for (int i = mid; i <=n- p; i++) {
			ll aff = a[mid] + m - a[i];
			if (aff < 0) {
				sum = -INF;
				break;
			}
			sum += aff;
		}

		if (sum >= m * v) {
			r = mid;
		}
		else {
			l = mid;
		}
		//cout << sum << endl;
		mid = (l + r) / 2;
		//cout << l << " " << mid << " "<< r << endl;
		if (r == 0 && l == -1) {
			break;
		}
	}

	cout << n - r << endl;

}