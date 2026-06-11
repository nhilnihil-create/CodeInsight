#include <bits/stdc++.h>
 
//#define endl '\n'
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

string s;
deque<char> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int Q, inv = 0;
	cin >> s >> Q;

	for (char c : s)
		q.push_back(c);

	while (Q--) {
		int t, a;
		char c;
		cin >> t;
		if (t == 1) inv ^= 1;
		else {
			cin >> a >> c;
			a--;
			if (a ^ inv) q.push_back(c);
			else q.push_front(c);
		}
	}

	while (q.size()) {
		if (inv) {
			cout << q.back();
			q.pop_back();
		} else {
			cout << q.front();
			q.pop_front();
		}
	}
	cout << endl;

	return 0;
}