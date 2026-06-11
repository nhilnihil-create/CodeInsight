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
	ll x, a;
	cin >> x >> a;
	cout << (x < a ? 0 : 10) << endl;
}