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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s;

void go (int i, char c, int f) {
	if (i == n) {
		cout << s << endl;
		return;
	}

	for (char x = 'a'; x <= c; x++) {
		s[i] = x;
		go(i + 1, c, 1);
	}

	if (f) {
		s[i] = c + 1;
		go(i + 1, c + 1, 1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	s.resize(n);
	go(0, 'a', 0);

	return 0;
}
