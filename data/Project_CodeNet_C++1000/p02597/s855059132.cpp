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
// #define int long long
// #define pow mypow

typedef pair<int,int> pii;
const int N = 2e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

int n;
string s;
int left_white[N], right_red[N];
int32_t main()
{
	IOS
	cin >> n >> s;
	s = '*' + s;
	for(int i=1; i<=n; i++) 
		left_white[i] = left_white[i-1] + (s[i] == 'W');
	for(int i=n; i>=1; i--) 
		right_red[i] = right_red[i+1] + (s[i] == 'R');

	int ans = INF;
	for(int r=0; r<=n; r++){ //last position of red
		int min_operations = max(left_white[r], right_red[r+1]);
		ans = min(ans, min_operations);
	}
	cout << ans << endl;
	return 0;
}
