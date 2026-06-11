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

int main(){
	st l;
	cin >> l;
	ll n = l.size();
	vll dp1(n + 1, 0), dp2(n + 1, 0);
	dp1.at(0) = 0, dp2.at(0) = 1;
	rep(i, 0, n){
		dp1.at(i + 1) = (dp1.at(i) * 3 + (l.at(i) == '1' ? dp2.at(i) : 0)) % mod;
		dp2.at(i + 1) = (l.at(i) == '1' ? 2 : 1) * dp2.at(i) % mod;
		if(i == n - 1){
			dp1.at(i + 1) = (dp1.at(i + 1) + dp2.at(i + 1)) % mod;
		}
	}
	cout << dp1.at(n) << endl;	
}