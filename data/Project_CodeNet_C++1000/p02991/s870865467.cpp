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
	ll n, m;
	cin >> n >> m;
	vvll graph(n);
	rep(i, 0, m){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		graph.at(u).push_back(v);
	}
	ll s, g;
	cin >> s >> g;
	s--; g--;

	queue<pll> que;
	vvll dis(n, vll(3, -1));
	dis.at(s).at(0) = 0;
	que.push(make_pair(s, 0));
	while(que.size()){
		ll v = que.front().first, mod3 = que.front().second;
		que.pop();
		vrep(nv, graph.at(v)) if(dis.at(nv).at((mod3 + 1) % 3) == -1) {
			que.push(make_pair(nv, (mod3 + 1) % 3));
			dis.at(nv).at((mod3 + 1) % 3) = dis.at(v).at(mod3) + 1;
		}
	}
	cout << (dis.at(g).at(0) == -1 ? dis.at(g).at(0) : dis.at(g).at(0) / 3) << endl;
}