#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n;
	long long int ans = 0;
	cin >> n;
	vector<int> a(n+1), b(n);
	for (int i = 0; i < n+1; i++) {
		cin >> a.at(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> b.at(i);
	}
	for (int i = 0; i < n ; i++) {
		if (b.at(i) <= a.at(i))ans += b.at(i);
		else {
			ans += a.at(i);
			if (a.at(i + 1) >=b.at(i)- a.at(i)) {
				ans += b.at(i) - a.at(i);
				a.at(i + 1) = a.at(i + 1) -(b.at(i)- a.at(i));
			}
			else {
				ans += a.at(i + 1);
				a.at(i + 1) = 0;
			
			}
			
		}
	}
	cout << ans << endl;
		return 0;
	}
