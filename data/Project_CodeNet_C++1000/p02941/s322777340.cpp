#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 998244353;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
ll Base = 101;

ll a[Maxn], b[Maxn];
set<pll> st;
ll n;

ll nx(ll i){
	return (i + 1) % n;
}
ll bef(ll i){
	return (i - 1 + n) % n;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		st.insert({-b[i], i});
	}
	ll ans = 0;
	while(!st.empty()){
		ll ind = st.begin() -> S;
		//cerr << ind << '\n';
		st.erase(st.begin());
		if(b[ind] <= a[ind]) continue;
		ll up = max({a[ind], b[bef(ind)], b[nx(ind)]});
		//cerr << ind << ' ' << up << '\n';
		if(up > b[ind]) continue;
		
		ll d = b[bef(ind)] + b[nx(ind)];
		ll stp = (b[ind] - up) / d;
		stp = max(stp, 1LL);
		if(stp > 0){
			b[ind] -= (stp * d);
			if(b[ind] < a[ind]) return cout << -1, 0;
			//cerr << ind << ' ' << b[ind] << '\n';
			st.insert({-b[ind], ind});
			ans += stp;
		}
	}
	for(int i = 0; i < n; i++) if(a[i] != b[i]) return cout << -1, 0;
	cout << ans << '\n';
	return 0; 
}

/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/