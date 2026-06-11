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
	
	ll n, a;
	cin >> n;
	ll cnt[n+1];
	memset(cnt, 0, sizeof(cnt));
	zep(i, 0, n){
		cin >> a;
		cnt[a]++;
	}
	//printa(cnt, 1, n)
	
	priority_queue<ll> q;
	rep(i, 1, n){
		if(cnt[i] > 0){
			q.push(cnt[i]);
		}
	}
	
	ll ans[n+1];
	memset(ans, 0, sizeof(ans));
	ll z = n;
	ll c = 0;
	ll l = 1;
	rrep(u, n, 1){
		//cout << u << z << endl;
		ll r = z/u;
		
		rep(i, l, r){
			ans[i] = u;
		}
		l = r+1;
		
		while(!q.empty() && q.top() == u){
			c++;
			q.pop();
		}
		if(z > 0){
			z -= c;
		}
	}
	
	rep(i, 1, n){
		print(ans[i])
	}
	return 0;
}