#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define st first
#define nd second
#define endl '\n' //toggle off for interactive problems
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
const int N = 1e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

string s;
map<string, int> m;
int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	m["RRR"] = 3;
	m["RRS"] = 2;
	m["RSR"] = 1;
	m["RSS"] = 1;
	m["SRR"] = 2;
	m["SRS"] = 1;
	m["SSR"] = 1;
	m["SSS"] = 0;
	cin >> s;
	cout << m[s] << endl;
	return 0;
}
