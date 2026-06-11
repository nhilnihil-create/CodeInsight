
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;

#define deb(x) cout << #x": " << (x) << endl;

const int N = 1e6+5;
const lli INF = 1e18;
const lli MOD = 1e9+7;
const ld EPS = 1e-4;



// ---- コーディングはここから！ ('-')7

int dp[N][4];
int n;
lli f(int u, int ma){
	if(u==n)return (ma==3);
	if(dp[u][ma]!=-1)return dp[u][ma];
	lli res = 8ll * f(u+1,ma) % MOD;
	res = (res + f(u+1,ma|1))%MOD;
	res = (res + f(u+1,ma|2))%MOD;
	dp[u][ma]=res;
	return dp[u][ma] = res;

}
void solve(){
	cin>>n;
	memset(dp, -1, sizeof dp);
	cout<<f(0,0)<<ENDL;
}
int main(){_
	//int t; cin>>t; while(t--)

	solve();
}
