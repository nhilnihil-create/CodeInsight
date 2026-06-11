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
	int k;
	cin >> k;
	queue<ll> q;
	for(int i = 1; i < 10; i++)	
		q.push(i);
	ll prev;
	while(k--) {
		ll t = q.front();
		prev = t;
		q.pop();
		if(t%10!=0) q.push(10*t+(t%10)-1);
		q.push(10*t + t%10);
		if(t%10!=9) q.push(10*t + t%10 +1);
	}
	cout << prev << endl;
	return 0;
}

