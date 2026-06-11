#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	multiset<int> m;
	vi v;
	for(int i=0;i<(1<<n);i++) {
		int t;
		cin >> t;
		m.insert(-t);
	}
	int e = *m.begin();
	v.PB(e); m.erase(m.begin());
	for(int i=0;i<n;i++) {
		int sz = v.size();
		for(int j=0;j<sz;j++) {
			auto it = m.upper_bound(v[j]);
			if(it == m.end()) {
				cout << "No" << endl;
				return 0;
			}
			v.PB(*it);
			m.erase(it);
		}
	}
	cout << "Yes" << endl;

}



