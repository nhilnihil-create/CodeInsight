#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n+1);
	rep(i,n+1) cin >> a[i];
	if(n >= 1 && a[0] != 0){
		cout << -1 << endl;
		return 0;
	}
	if(n == 0 && a[0] != 1){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	vector<ll> sup(n+1);
	sup[n] = a[n];
	for (int j = n-1; j >= 0; --j) {
		sup[j] += a[j] + sup[j+1];
	}
	ll prev = 1;
	ans += 1;
	REP(i,n){
		ll node = min(sup[i], prev*2);
		ans += node;
		prev = node - a[i];
		if(prev < 0){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
    return 0;
}