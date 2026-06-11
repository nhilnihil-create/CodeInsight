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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	for (int i = 1; i < 100000; i++) {
		if (i * 8 / 100 == a && i * 10 / 100 == b) {
			cout << i << endl;
			return 0;
		}
	}

	cout << - 1 << endl; 

	return 0;
}