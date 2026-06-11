#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 300005;

set<pair<int,int>> t;
map<int,int> r;
map<int,int> c;

bool cmp1(const int &a, const int &b) {
	return r[a]>r[b];
}
bool cmp2(const int &a, const int &b) {
	return c[a]>c[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int h,w;
	cin >> h >> w;
	
	int m;
	cin >> m;
	
	while(m--){
		int x, y;
		cin >> x >> y;
		t.insert({x,y});
		r[x]++;
		c[y]++;
	}
	
	vector<int> rows;
	vector<int> cols;
	
	for (auto &p : r) {
		rows.pb(p.F);
	}
	for (auto &p : c) {
		cols.pb(p.F);
	}	
	
	sort(rows.begin(),rows.end(),cmp1);
	sort(cols.begin(),cols.end(),cmp2);
	
	while(r[rows[0]]!=r[rows.back()]) {
		rows.pop_back();
	}
	while(c[cols[0]]!=c[cols.back()]) {
		cols.pop_back();
	}
	
	int ans = r[rows[0]]+c[cols[0]];
	
	if (rows.size() * cols.size() > m){
		cout << ans << "\n";
		return 0;
	}
	
	bool found = false;
	
	FOR(i,0,SZ(rows)) {
		FOR(j,0,SZ(cols)) {
			if (!t.count({rows[i],cols[j]})) {
				found = true;
				break;
			}
		}
		
	}
	
	if (! found) {
		ans--;
	}
	
	cout << ans << "\n";
	
	
}
