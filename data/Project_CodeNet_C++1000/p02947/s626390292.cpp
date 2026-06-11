#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n;
	cin >> n;
	map<string, int> mp;
	ll ans = 0;
	rep(i, n) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		mp[s]++;
	}
	for (auto& p : mp) {
		int a = p.second;
		ans += (ll)a*(a - 1) / 2;
	}
	cout << ans << endl;

	return 0;
}