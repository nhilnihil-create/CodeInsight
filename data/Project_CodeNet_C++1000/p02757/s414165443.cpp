#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define PB push_back
#define F first
#define S second

typedef unsigned long long llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int INF = 1e9+10;
const ll MOD = 1e9+7;

void solve(){
	int n, p; cin >> n >> p;
	string s; cin >> s;

	if(p == 2){
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if((s[i]-'0')%2 == 0){
				ans += i+1;
			}
		}
		cout << ans << '\n';
		return;
	}

	if(p == 5){
		ll ans = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '5' || s[i] == '0'){
				ans += i+1;
			}
		}
		cout << ans << '\n';
		return;
	}

	map<int,int> m;
	ll ans = 0;
	ll atual = 0;
	ll p10 = 1;
	m[0] = 1;
	for(int i = n-1; i>=0; i--){
		atual = ((s[i]-'0')*p10 + atual)%p;
		ans += m[atual];
		m[atual]++;
		p10 = (p10 * 10) % p;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t=1; //cin >> t;
	while(t--){
		solve();
	}

	return 0;
}