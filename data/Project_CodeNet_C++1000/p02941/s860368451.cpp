#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	ll a[n], b[n];
	priority_queue<P> q;
	zep(i, 0, n){
		cin >> a[i];
	}
	bool f;
	zep(i, 0, n){
		cin >> b[i];
		if(b[i] > a[i]){
			q.push(P(b[i], i));
		}
		if(b[i] < a[i]){
			f = false;
		}
	}
	if(f){print(-1) return 0;}
	
	ll ans = 0;
	while(!q.empty()){
		ll at = q.top().second;
		q.pop();
		
		ll l = b[(at+n-1)%n];
		ll r = b[(at+1)%n];
		ll tmp = max((b[at]-max(a[at], max(l, r)))/(l+r), 1LL);
		b[at] -= tmp*(l+r);
		ans += tmp;
	
		if(b[at] < a[at]){
			ans = -1;
			break;
		}
		if(b[at] > a[at]){
			q.push(P(b[at], at));
		}
	}
	print(ans)
	return 0;
}