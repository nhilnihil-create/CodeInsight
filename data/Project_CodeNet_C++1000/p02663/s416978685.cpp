#include<bits/stdc++.h>
// Begin Header {{{
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<lli>>;
using P = pair<int, int>;
// }}} End Header

int main(){
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int ans = (60*h2+m2) - (60*h1+m1) - k;
	if(ans < 0) ans = 0;
	cout << ans << endl;
	return 0;
}