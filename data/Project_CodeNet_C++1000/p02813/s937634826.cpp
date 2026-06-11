#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	int n;
	cin >> n;
	vector<double> vs(n);
	vector<double> os(n);
	rep(i, n) {
		cin >> vs[i];
	}
	rep(i, n) {
		cin >> os[i];
	}
	vector<int> visit;
	rep(i, n) visit.push_back(i+1);

	ll id1 = -1, id2 = -1;
	ll index = 0;
	do {
		index++;
		{
			if (id1 < 0) {
				bool ok = true;
				rep(i, n) {
					if (vs[i] != visit[i]) ok = false;
				}
				if (ok) {
					id1 = index;
				}
			}
		}
		{
			if (id2 < 0) {
				bool ok = true;
				rep(i, n) {
					if (os[i] != visit[i]) ok = false;
				}
				if (ok) {
					id2 = index;
				}
			}
		}
	} while (std::next_permutation(visit.begin(), visit.end()));
	cout << abs(id2- id1) << endl;
	return 0;
}
