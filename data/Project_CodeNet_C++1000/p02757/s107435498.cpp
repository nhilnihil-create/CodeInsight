#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double
#define rep(i, x, n, j) for(int i=x;i<(int)n;i+=j)
#define F first
#define S second
#define per(i, x, n, j) for(int i=(int)n-1;i>=0;i-=j)
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()

const int N = 2000100;
const ll MOD = 1e9+7;
const ll inf = 1e18+5;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int _;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	/*if(k==2 || k==5){
		ll counter=1ll;
		rep(i,0,sz(s),1) if((s[i]-'0')%k == 0) ++counter;
		cout << (((counter-1)*counter)/2ll);
		exit(0);
	}*/
	if (10%k == 0) { // 2,5
    ll ans = 0;
    rep(r,0,n,1) {
      if ((s[r]-'0') % k == 0) {
        ans += r+1;
      }
    }
    cout << ans << endl;
    return 0;
  }
	else{
		vector<ll> d(n+1, 0ll);
		ll mul = 1ll;
		map<ll, ll> mp;
		mp[0]++;
		for(int i=n-1; i>=0; --i){
			ll h = (s[i]-'0');
			d[i] = ((h*mul)+d[i+1])%k;
			mp[d[i]]++;
			mul*=10ll; mul%=k;
		}
		vector<int> cnt(k);
		ll ans = 0;
		for (int i = n; i >= 0; --i) {
			ans += cnt[d[i]];
			cnt[d[i]]++;
		}
		cout << ans << endl;
		/*ll ans = 0ll;
		for(auto &x: mp)
			ans += ((x.S-1)*x.S)/2ll;

		cout << ans << endl;*/
	}
	return 0;
}
