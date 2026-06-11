#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int tmp;
	ll ans = 0;
	int n;
	cin >> n;
	ll a[n+1], sum = 0;
	REP(i, n+1){
		cin >> a[i];
		sum += a[i];
	}
	bool ch = true;
	ll now = 1;
	REP(i, n+1){
		if(now < a[i]) ch = false;
		ans += now;
		sum -= a[i];
		now -= a[i];
		now = min(sum, now * 2);
	}
	if(ch)cout << ans << endl;
	else cout << -1 << endl;
}
