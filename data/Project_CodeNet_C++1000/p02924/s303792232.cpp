#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i < n; i++) {
		sum += i;
	}
	cout << sum << endl;
	return 0;
}