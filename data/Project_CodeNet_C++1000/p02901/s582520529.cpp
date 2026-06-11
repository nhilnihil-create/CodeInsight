#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=1<<12;
int dp[1005][mxn];
bitset<12>bs[1005];
int cost[1005],sz[1005];

void mins(int &a, int b){
	a = min(a,b);
	return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m; cin >> n >> m;
	for(int i=1; i<=m; i++){
		int x;
		cin >> cost[i] >> sz[i];
		for(int j=0; j<sz[i]; j++){
			cin >> x; x--;
			bs[i][x]=1;
		}
	}
	for(int i=0; i<=m; i++)
		for(int j=0; j<(1<<n); j++)
			dp[i][j]=1e9;
	dp[0][0]=0;
	for(int i=1; i<=m; i++){
		ll now = bs[i].to_ulong();
		for(int j=0; j<(1<<n); j++){
			mins(dp[i][j],dp[i-1][j]);
			if(dp[i-1][j]!=1e9){
				ll cur = now|j;
				mins(dp[i][int(cur)],dp[i-1][j]+cost[i]);
			}
		}
	}
	if(dp[m][int(1<<n)-1]==1e9)dp[m][int(1<<n)-1]=-1;
	cout << dp[m][int(1<<n)-1] << '\n';
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
