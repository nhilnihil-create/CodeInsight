#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll n;
	cin >> n;
	if (n % 2 == 1) cout << 0 << endl;
	else {
		ll k = 5;
		ll t = 0;
		while (k <= n) {
			t += n / k / 2;

			k *= 5;
		}
		cout << t << endl;
	}
}