#include<bits/stdc++.h>
using namespace std;
//Optimisations
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
//shortcuts for functions
#define pb push_back
#define mp make_pair
#define ff first 
#define ss second
#define all(v) v.begin(),v.end()
#define prec(n) fixed<<setprecision(n)
#define n_l '\n'
// make it python 
#define gcd __gcd
#define append push_back
#define str to_string
// utility functions shortcuts
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define sswap(a,b) {a=a^b;b=a^b;a=a^b;}
#define swap(a,b) {auto temp=a; a=b; b=temp;}
#define init(dp) memset(dp,-1,sizeof(dp));
#define set0(dp) memset(dp,0,sizeof(dp));
#define bits(x) __builtin_popcount(x)
#define SORT(v) sort(all(v))
#define endl "\n"
#define forr(i,n) for(ll i=0;i<n;i++)
// declaration shortcuts
typedef long long int ll;
#define int ll
// Constants
constexpr int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
constexpr ll INF = 1999999999999999997; 
constexpr int inf= INT_MAX;
constexpr int MAXSIZE = int(1e6)+5;
constexpr auto PI  = 3.14159265358979323846L;
constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr auto MOD = 1000000007;
constexpr auto MOD9 = 1000000009;
constexpr auto maxn = 100006;
//void IOfile(){
//freopen(file_name, reade_mode, stdin);
//freopen(file_name, write_mode, stdout);
//}
void fastio(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

int dp[2002][2002];
int n;
vector<pair<int,int>>a(2002);

int solve(int ind, int from_front){
	if(ind > n) return 0;
	int &res = dp[ind][from_front];
	if( res != -1) return res;
	res = 0;
	int from_back =   (ind  - 1  - (from_front)) ;
	res = max({res,
				a[ind].first * abs(a[ind].second - (from_front + 1)) + solve(ind + 1,from_front + 1) , 
				a[ind].first * abs(a[ind].second - ( n  - (from_back))  ) + solve(ind + 1, from_front)
			});
	return res;
}

int32_t main(){
	fastio();
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[i] = {x, i};
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	reverse(a.begin() + 1, a.begin() + n + 1);
	memset(dp , -1 , sizeof(dp));
	int ans = 0;
	
		ans = max({ans,a[1].first * abs(1  - a[1].second) + solve(2,1) , a[1].first * abs(n - a[1].second) + solve(2,0)});
	
	cout << ans;
}