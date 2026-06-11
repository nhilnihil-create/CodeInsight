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

map<ii,int>mp;

ii f(int x){
	int a = x%10;
	int b = 0;
	while(x){
		b = x;
		x /= 10;
	}
	return ii(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		ii x = f(i);
		mp[x]++;
	}
	ll ans = 0LL;
	for(int i=1; i<=n; i++){
		ii now = f(i);
		ii opp(now.se,now.fi);
		ans += mp[opp];
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
