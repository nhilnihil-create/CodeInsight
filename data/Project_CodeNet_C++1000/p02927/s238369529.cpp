#include <bits/stdc++.h>

#define f(i,a,b) for( ll  i = a; i < (ll) b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inter   ios::sync_with_stdio(false);cin.tie(0)

// policy-based



using namespace std;


typedef long long ll; // int or long long
typedef long double ld;
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;



 
const ll MAX = 1e5 + 100;
const ll inf = 1e9;
const ll mod = 1e9+7;



int main(){
	fastio;
	ll m,d,ans = 0;
	cin >> m >> d;
	f(i,1,m+1){
		f(j,10,d+1){
			ll x = j/10, y = j%10;
			if(x>1 && y>1 && x*y == i) ans++;
		}
	}
	cout << ans << endl;
}