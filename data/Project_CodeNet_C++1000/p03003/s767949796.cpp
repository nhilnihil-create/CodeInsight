/*
 *  AUTHOR : MANAV PATEl
*/
#include<bits/stdc++.h>
#include<functional>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

namespace fastio {

	template <class T> istream &operator>>(istream &os, vector<T> & vec) {
		for (auto &u : vec)os >> u;
		return os;
	}
	template <class T> ostream &operator<<(ostream &os, const vector<T> & vec) {
		for (auto &u : vec)os << u << " ";
		return os;
	}
	template<class T1, class T2> inline istream& operator>>(istream& os, pair<T1, T2>& p) {
		return os >> p.first >> p.second;
	}
	template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
		return os << p.first << " " << p.second;
	}
	template <class T> ostream &operator<<(ostream &os, set<T> & con) {
		for (auto &u : con) os << u << " ";
		return os;
	}
	void re() {}
	template <typename T, typename... args> void re(T& x, args&... tail) {
		cin >> x;
		re(tail...);
	}
	void pr() {}
	template <typename T> void pr(const T& x) {
		cout << x;
	}
	template <typename T, typename... args> void pr(const T& x, const args&... tail) {
		cout << x << " ";
		pr(tail...);
	}
	template <typename... args> void prln(const args&... tail) {
		pr(tail...);
		cout << "\n";
	}
}
using namespace fastio;

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;
const ll mod1 = 998244353;

#define fill(a)  memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

ll dp0[2005][2005];
ll dp1[2005][2005];

int main()
{
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.tie(0);
	int n, m;
    cin >> n >> m;
    vector<int> s(n+2, -1), t(m+2, -2);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> t[i];
    }
    dp0[0][0] = 1;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            dp0[i+1][j] = (dp0[i+1][j] + dp0[i][j]) % mod;
            dp1[i][j] = (dp1[i][j] + dp0[i][j]) % mod;
            dp1[i][j+1] = (dp1[i][j+1] + dp1[i][j]) % mod;
            if(s[i] == t[j]){
                dp0[i+1][j+1] = (dp0[i+1][j+1] + dp1[i][j]) % mod;
            }
        }
    }
    cout << dp1[n][m] << endl;
}
