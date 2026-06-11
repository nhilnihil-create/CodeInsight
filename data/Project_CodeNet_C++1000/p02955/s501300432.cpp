#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#ifdef LOCAL
#define what_is(x) cerr << #x << " is " << x << endl;
#define debug(v) {for (auto x : v) cerr << x << ' '; cerr << endl;}
#else
#define what_is(x)
#define debug(v)
#endif

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int n, k;
	scanf("%d%d", &n, &k);
	vi a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int s = accumulate(all(a), 0);
	set<int> factors;
	for (int i = 1; i * i <= s; i++) {
		if (s % i == 0) {
			factors.insert(i);
			factors.insert(s/i);
		}
	}

	int answer = 1;
	for (int f : factors) {
		int op = 0;
		vi r(n);
		for (int i = 0; i < n; i++) r[i] = a[i] % f;
		sort(all(r));
		for (int i = 0, j = n-1; i < j; i++) {
			op += r[i];
			while (r[j]+r[i] > f) {
				r[i] -= f - r[j];
				r[j] = f;
				j--;
			}
			if (r[i] > 0) {
				r[j] += r[i];
				r[i] = 0;
			}
		}

		if (op <= k) answer = max(answer, f);
	}
	printf("%d\n", answer);
}
