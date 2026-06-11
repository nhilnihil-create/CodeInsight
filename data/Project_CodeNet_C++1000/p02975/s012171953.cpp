#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, res[MX];
multiset<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		int a;
		cin >> a;
		st.insert(a);
	}

	res[0] = *st.begin();
	st.erase(st.find(res[0]));

	res[1] = *st.rbegin();
	st.erase(st.find(res[1]));

	for (int i = 2; i < n; i++) {
		auto it = st.find(res[i - 1] ^ res[i - 2]);
		if (it == st.end()) {
			cout << "No" << endl;
			return 0;
		}
		res[i] = *it;
		st.erase(it);
	}

	forn (i, n)
		if ((res[i] ^ res[(i + 2) % n]) != res[(i + 1) % n]) {
			cout << "No" << endl;
			return 0;
		}

	cout << "Yes" << endl;

	return 0;
}
