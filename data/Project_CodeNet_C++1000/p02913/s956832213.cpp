#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int n;
string s;

bool check(int len) {
	map<string, int> seen, first;
	for(int i = 0; i <= n - len; i++) {	
		string t = s.substr(i, len);
		if(seen[t] && first[t] + len <= i) return true;
		else {
			seen[t] = 1;
			if(!first.count(t)) first[t] = i;
		}
	}
	
	return false;
}

void solve() {
	cin >> n >> s;
	
	int l = 0, r = n / 2, ans = 0;
	while(l <= r) {
		int mid = (r + l) / 2;
		if(check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else r = mid - 1;
	}
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}