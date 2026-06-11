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

int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	int x, y;
 	cin >> x >> y;
 	int ans = 0;
 	if(x==1) ans += 300000;
 	else if(x==2) ans += 200000;
 	else if(x==3) ans += 100000;
 	if(y==1) ans += 300000;
 	else if(y==2) ans += 200000;
 	else if(y==3) ans += 100000;
 	if(x==1&&y==1) ans += 400000;
 	cout << ans;
	return 0;
}
