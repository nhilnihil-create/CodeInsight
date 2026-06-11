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

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[Maxn], p[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll s = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[i] = (a[i] >= 0);
		s += p[i];
	}
	if(s == n || s == 0){
		ll mn = 1000000;
		for(int i = 1; i <= n; i++) mn = min(mn, abs(a[i]));
		for(int i = 1; i <= n; i++){
			if(mn == abs(a[i])){
				p[i] = 1-p[i];
				break;
			}
			
		}
	}
	ll i0, i1;
	ll res = 0;
	for(int i = 1; i <= n; i++){
		if(p[i] == 1) i1 = i;
		else i0 = i;	
		res += (p[i] == 1 ? a[i] : -a[i]);
	}
	cout << res << '\n';
	for(int i = 1; i <= n; i++){
		if(i == i1 || i == i0) continue;
		if(p[i] == 1){
			cout << a[i0] << " " << a[i] << '\n';
			a[i0] -= a[i];
		}
		if(p[i] == 0){
			cout << a[i1] << " " << a[i] << '\n';
			a[i1] -= a[i];
		}
	}
	cout << a[i1] << " " << a[i0] << '\n';
	return 0;
}
/*
1
5 1
20 21 22 23 24

1
4 2 
1 2 3 4

2 4 1 3

*/
