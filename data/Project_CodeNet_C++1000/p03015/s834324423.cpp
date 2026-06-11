#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using ch = char;
using db = double;
using bl = bool;
using vll = vector<long long>;
using vdb = vector<db>;
using vvll = vector<vll>;
using vst = vector<st>;
using vch = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;return true;} return false;}
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;return true;} return false;}
const ll mod = 1000000007;
const ll inf = 1LL << 60;

ll modpow(ll a, ll n){
  ll ans = 1;
  while(n > 0){
    if(n & 1) ans = ans * a % mod;
    n >>= 1;
    a = a * a % mod;
  }
  return ans;
}

ll n;
st l;

ll saiki(ll i){
	if(i == n - 1){
		if(l.at(i) == '1') return 3;
		return 1;
	};
	if(l.at(i) == '0') return saiki(i + 1);
	return (2 * saiki(i + 1) + modpow(3, n - 1 - i)) % mod;
}

int main(){
	cin >> l;
	n = l.size();
	cout << saiki(0) << endl;
}