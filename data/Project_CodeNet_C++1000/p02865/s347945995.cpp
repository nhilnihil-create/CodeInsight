#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
int n;
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	if(n&1) cout << n/2;
 	else cout << n/2-1;
	return 0;
}
