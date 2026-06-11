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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int r=0, g=0, b=0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R') r++;
		else if(s[i] == 'G') g++;
		else b++;
	}
	ll tot = 1ll*r*g*b;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int k = 2*j-i;
			if(k < n && s[i]!=s[j]&&s[j]!=s[k]&&s[i]!=s[k]) tot--;
		}
	}
	cout << tot << endl;

	return 0;
}

