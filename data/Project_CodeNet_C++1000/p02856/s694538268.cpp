#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define what_is(x) cerr << #x << " is " << x << endl;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int m; scanf("%d", &m);
	ll cnt = 0;
	for (int i = 0; i < m; i++) {
		ll d, c; scanf("%lld%lld", &d, &c);
		cnt += c * (9 + d);
	}

	ll answer;
	if (cnt <= 18)
		answer = 0;
	else
		answer = (cnt - 10) / 9;
	printf("%lld\n", answer);
}
