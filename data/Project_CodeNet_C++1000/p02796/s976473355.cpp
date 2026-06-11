#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	V<P> rob(n);
	rep(i, n) {
		int x, l;
		cin >> x >> l;
		rob[i] = make_pair(x, l);
	}

	sort(all(rob));

	stack<P> can;
	can.push(rob[0]);

	rep1(i, n - 1) {
		if (can.top().first + can.top().second <= rob[i].first - rob[i].second)can.push(rob[i]);
		else if(can.top().first + can.top().second > rob[i].first + rob[i].second) {
			can.pop();
			can.push(rob[i]);
		}
	}

	cout << can.size() << endl;

}