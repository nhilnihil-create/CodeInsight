#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

vector<pair<ll, char>> RLE(const string &s) {
	ll cnt = 0;
	ll n = s.length();
	vector<pair<ll, char>> res;
	for (ll i = 0; i < s.size(); i++) {
		cnt++;
		if (i == (ll)s.size()-1) {
			res.push_back(make_pair(cnt,s[i]));
			break;
		}
		if (s[i] != s[i+1]) {
			res.push_back(make_pair(cnt,s[i]));
			cnt = 0;
		}
	}
	return res;
}

int main(int argc, char const *argv[]) {
    ll n,k; cin>>n>>k;
    string s; cin>>s;

    vector<pair<ll, char>> t = RLE(s);
    int ans = 0;
    for (auto &&e: t) ans += e.first-1;

    cout << min(n-1, ans+k*2) << '\n';

    return 0;
}