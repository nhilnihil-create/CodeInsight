#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////

#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll LINF = 1e18;
const ll INF = 1e9;
const int MOD = 1e9+7;

/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////

int main(){
	fastio;
	ll n, d, a;
	cin >> n >> d >> a;
	vector<pll> v(n);
	for(pll& x : v){
		cin >> x.fs >> x.sc;
	}
	sort(v.begin(), v.end());
	ll ans = 0, qtd = 0, ponto = 0;
	set<pll> rmv;
	for(int i = 0; i < n; i++){
		for(auto& x : rmv){
			if(x.fs < v[i].fs){ /// se tem um range que ja passou, removo o dano dele
				qtd -= x.sc;
				rmv.erase(x);
			}else{
				break;
			}
		}
		v[i].sc -= qtd;
		if(v[i].sc <= 0) continue; /// morreu
		//cout << a << endl;
		ll k = (v[i].sc + a-1)/a;
		ans += k;
		qtd += k*a;
		ponto = v[i].fs+2*d;
		rmv.insert({ponto, k*a});
	}
	cout << ans << endl;
	return 0;
}