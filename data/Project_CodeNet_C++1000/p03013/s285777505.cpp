//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ll((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define roF(i,a,b) for(ll i = ll(a); i >= ll(b); i--)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll N=1e6;
const ll MOD = 1e9+7;

int n;
bool broken[N];
ll dp[N];

ll go(ll x){
	if(dp[x]!=-1) return dp[x];
	if(broken[x]) return dp[x]=0;
	return dp[x] = (go(x-1)+go(x-2))%MOD;
}	

int main(){
	fastio;
	cin>>n;
	int m; cin>>m;
	For(i,0,m){
		ll x; cin>>x;
		broken[x]=1;
	}
	For(i,1,n+1) dp[i]=-1;
	dp[0]=1;
	cout << go(n) << endl;
	return 0;
}

