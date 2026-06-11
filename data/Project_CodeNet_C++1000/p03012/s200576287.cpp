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
const ll INF = 1e18;

ll A[N], acum[N];

int main(){
	fastio;
	int n; cin>>n;
	For(i,1,n+1) cin>>A[i];
	For(i,1,n+1) acum[i]=A[i]+acum[i-1];
	ll ans = INF;
	For(i,1,n+1){
		ll s1 = acum[i];
		ll s2 = acum[n]-acum[i];
		ans = min(ans, abs(s1-s2));
	}
	cout << ans << endl;
	return 0;
}

