#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll n;
	cin >> n;
	string ans = "";
	ll t = n;
	while (t > 0) {
		t -= 1;
		int d = t % 26;
		ans += 'a' + d;
		t /= 26;
	}
	reverse(ALL(ans));
	cout << ans << endl;
}