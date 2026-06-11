#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define deb(x) cout << #x << " " << x << endl;
#define debarr(x) for (auto i : x) cout << i << " "; cout << endl;
#define debtwo(x,y) cout << #x << " " << x << ", " << #y << " " << y << endl;
#define mod 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int mx = (n - 1) / 2;
	int res = 0;
	for (int i = 1; i <= mx; i++) {
		res += (n - 1) / i;
	}
	for (int i = mx + 1; i < n; i++) res++;
	cout << res;
}