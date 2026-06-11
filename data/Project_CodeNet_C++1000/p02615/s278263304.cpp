#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	sort(a.rbegin(),a.rend());
	vector<ll> b;
	REP(i,n-1){
		b.push_back(a[i]);
		b.push_back(a[i]);
	}
	ll ans = a[0];
	rep(i,n-2){
		ans += b[i];
	}
	cout << ans << endl;
    return 0;
}

