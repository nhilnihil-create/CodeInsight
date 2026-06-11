#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VPP vector<pair<int,pair<int,int>>>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)
typedef pair <int, int> P;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;



int main() {

	ll n, k;
	cin >> n >> k;

	VLL a(n);
	REP(i, n) {
		cin >> a[i];
		a[i]--;
	}
	VLL s(n + 1);
	s[0] = 0;
	REP(i, n)s[i + 1] = (s[i] + a[i]) % k;

	ll ans = 0;
	map<int, int> m;
	m[0]++;
	FOR(i, 1, n + 1) {
		if (i >= k) {
			m[s[i - k]]--;
		}
		ans += m[s[i]];
		m[s[i]]++;
	}
	cout << ans << endl;
	
}
