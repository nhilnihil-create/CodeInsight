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

bool comp(ii a, ii b) {
	if(a.ss < b.ss) return true;
	else if(a.ss > b.ss) return false;
	else if(a.ff > b.ff) return true;
	else return false;
}

void solve() {
	int n;
	cin >> n;
	
	vii p(n);
	for(int i = 0; i < n; i++) cin >> p[i].ff >> p[i].ss;
	
	sort(all(p), comp);
	ll t = 0;
	for(int i = 0; i < n; i++) {
		t += p[i].ff;
		if(t > p[i].ss) {
			cout << "No" << endl;
			return;
		}
	}
	
	cout << "Yes" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}