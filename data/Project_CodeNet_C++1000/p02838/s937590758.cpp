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

ll INF=LLONG_MAX;

int const mxn=3e5+5;
ll a[mxn];

void multi(ll &a, ll b){
	a%=MOD; b%=MOD; a*=b; a%=MOD;
	return;
}
void add(ll &a, ll b){
	a%=MOD; b%=MOD; a+=b; a%=MOD;
	return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n; cin >> n;
	map<int,ii>mp;
	for(int i=0; i<n; i++){
		cin >> a[i];
		for(int j=59; j>=0; j--){
			if(a[i]&(1LL<<j))mp[j].se++;
			else mp[j].fi++;
		}
	}
	ll ans = 0;
	for(int j=59; j>=0; j--){
		ll cur = (1LL<<j)%MOD;
		multi(cur,ll(mp[j].fi)*ll(mp[j].se)%MOD);
		add(ans,cur);
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
