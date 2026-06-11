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
#define pow mypow

typedef pair<int,int> pii;
const int N = 1e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

int pow(int a, int b){
	int res = 1;
	while(b){
		if (b&1) res = (res*a) % MOD;
		a = (a*a) % MOD;
		b /= 2;
	}
	return res;
}
int n, a, b;
int C(int n, int k){
	int cnt = n - max(k, n-k);
	int tu = 1, mau = 1;
	while(cnt){
		mau = (mau*cnt) % MOD;
		tu = (tu*(n-cnt+1)) % MOD;
		cnt--;
	}
	return tu*pow(mau, MOD-2) % MOD;
}
int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	cin >> n >> a >> b;
	int ans = pow(2, n)-1 - C(n, a) - C(n, b) + 2*MOD;
	cout << ans % MOD << endl;
	return 0;
}
