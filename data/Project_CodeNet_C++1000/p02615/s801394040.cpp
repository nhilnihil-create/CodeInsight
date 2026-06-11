#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define st first
#define nd second
#define endl '\n'
#define what_is(x) cerr << #x << " is " << x << endl;
#define what_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << e << ' '; cerr << '\n'; //vector, set
#define what_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << x[i] << ' '; cerr <<  '\n'; //n first element of array
#define cerr_pair(x) '{' << x.st << ", " << x.nd << '}'
#define pwhat_is(x) cerr << #x << " is " << cerr_pair(x) << endl;
#define pwhat_is_v(x) cerr << #x << " is "; for(auto&e: (x)) cerr << cerr_pair(e) << ' '; cerr << '\n'; //vector, set
#define pwhat_is_a(x, n) cerr << #x << " is "; for(int i=0;i<n;i++) cerr << cerr_pair(x[i]) << ' '; cerr <<  '\n'; //n first element of array
#define int long long
// #define pow mypow

typedef pair<int,int> pii;
const int N = 2e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

int n, a[N];
int32_t main()
{
	IOS
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n, greater<int>());
	int ans = a[0];
	n -= 2;
	int i;
	for(i=1; i<=n/2; i++) ans += 2*a[i];
	if (n&1) ans += a[i];
	cout << ans << endl;
	
	return 0;
}
