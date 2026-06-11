#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int a, b;
	cin >> a >> b;
	for(int i = 1; i <= 1251; i++) {
		if(i*8/100 == a && i/10 == b)	{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

