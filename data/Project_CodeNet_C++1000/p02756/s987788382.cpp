#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctz(x)
#define setbitsll(x) __builtin_popcountll(x)
#define zerobitsll(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef map<int,int> mii;

const int MOD = 1e9+7;

void solve () {
	string str;
	cin >> str;
	bool rev = false;	
	int q,type;
	cin >> q;
	deque<char>dq;
	for (int i = 0;i < str.length();++i) {
		dq.pb(str[i]);
	}
 	while (q--) {
		cin >> type;
		if (type == 1) {
			rev = !rev;
		} else {
			int f;char c;
			cin >> f >> c;
			if (f == 1) {
				if (rev) {
					dq.push_back(c);
				} else {
					dq.push_front(c);
				}
			} else {
				if (rev) {
					dq.push_front(c);
				} else {
					dq.push_back(c);
				}
			}
		}
	}
	string res = "";
	while (!dq.empty()) {
		res += dq.front();
		dq.pop_front();
	}
	if (rev) {
		reverse(all(res));
	}
	cout << res << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}

