#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

#define sz(x) int(x.size())
int main()
{
	string s, t;
	cin >> s >> t;

	int n = sz(s), m = sz(t);
	//indexのリストを作る
	vector<vector<int>> is(26);
	rep(i,n) is[s[i]-'a'].push_back(i);
	rep(i,n) is[s[i]-'a'].push_back(i+n);
	ll ans = 0;
	int p = 0;
	rep(i,m){
		int c = t[i] - 'a';
		if(sz(is[c]) == 0) {
			puts("-1");
			return 0;
		}
		p = *lower_bound(is[c].begin(), is[c].end(), p) + 1; // アスタリスクをつけると、値が帰ってくる
		if(p>=n) {
			p -= n;
			ans += n;
		}
	}
	ans += p;
	cout << ans << endl;

}
