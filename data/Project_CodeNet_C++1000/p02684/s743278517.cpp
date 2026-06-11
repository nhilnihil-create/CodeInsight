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
	ll k; 
	cin >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	if(k < n) {
		int now = 0;
		for(int i = 0; i < k; i++){
			now = a[now];
		}
		cout << now+1 << endl;
		return 0;
	}
	
	vector<int> used(n, -1);
	int li = 0;
	used[0] = 0;
	int now = 0;
	for(int i = 1; i < n; i++) {
		li = i;
		now = a[now];
		if(used[now] != -1)
			break;
		used[now] = i;
	}
	
	int diff = li - used[now];
	k -= li;
	k %= diff;
	for(int i = 0; i < k; i++) {
		now = a[now];
	}
	cout << now + 1 << endl;
	return 0;
}

