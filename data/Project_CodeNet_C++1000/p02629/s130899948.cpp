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
const int N = 1e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

int n;
int _pow26[12];
int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	cin >> n;
	_pow26[0] = 1;
	for(int i=1; i<12; i++) _pow26[i] = _pow26[i-1] * 26;
	for(int i=1; i<12; i++) {
		if (n > _pow26[i]) {
			n -= _pow26[i];
		} else {
			n -= 1;
			vector<int> ans(i);
			for(int j=0; j<i; j++) {
				ans[i-1-j] = n % 26;
				n /= 26;
			}
			for(int j=0; j<i; j++) cout << char(ans[j] + 'a');
			cout << endl;
			return 0;
		}
	}	

	return 0;
}
