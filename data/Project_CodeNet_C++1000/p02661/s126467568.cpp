#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <cctype>
#include <random>

using namespace std;
typedef long long  ll;
const ll INF = 1000000007;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (n % 2 == 0) {
		int l, r;
		l = a[n / 2 - 1] + a[n / 2];
		r = b[n / 2 - 1] + b[n / 2];
		cout << (r - l) + 1 << endl;
	}
	else {
		int l, r;
		l = a[(n + 1) / 2 - 1];
		r = b[(n + 1) / 2 - 1];
		cout << (r - l) + 1 << endl;
	}
	return 0;
}