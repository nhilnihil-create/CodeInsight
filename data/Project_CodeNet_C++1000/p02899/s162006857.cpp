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

void solve() {
	int n;
	cin >> n;
	
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vi ans(n);
	for(int i = 0; i < n; i++) ans[a[i] - 1] = i + 1;
	
	for(int i : ans) cout << i << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}