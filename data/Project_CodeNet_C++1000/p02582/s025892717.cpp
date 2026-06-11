#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=1e9+7;
const long double PI = acos(0);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	string s;
	cin >> s;
	int ans;
	if(s == "RRR") ans = 3;
	else if(s == "RRS" || s == "SRR") ans = 2;
	else if(s == "SSS") ans = 0;
	else ans = 1;
	cout << ans;
	
	return 0;
}