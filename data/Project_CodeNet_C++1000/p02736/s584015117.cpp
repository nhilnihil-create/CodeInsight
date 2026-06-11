#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 2;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, twosum[1000008];
string s;
bool use[3];

ll combo(ll n, ll k){
	return (twosum[n]-twosum[k]-twosum[n-k]) == 0;
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	twosum[0] = 0;
	rep(i, 1, 1e6){
		twosum[i] = twosum[i-1];
		ll tmp = i;
		while(tmp%2 == 0){
			twosum[i]++;
			tmp /= 2;
		}
	}
	
	cin >> n >> s;
	zep(i, 0, n){s[i]--;}
	//print(s)
	bool two = true;
	zep(i, 0, n){if(s[i] == '1'){two = false;}}
	if(two){zep(i, 0, n){if(s[i] == '2'){s[i] = '1';}}}
	
	ll ans = 0;
	zep(i, 0, n){
		if(s[i] == '1'){
			ans ^= combo(n-1, i);
		}
	}
	
	if(two){ans *= 2;}
	print(ans)
	return 0;
}