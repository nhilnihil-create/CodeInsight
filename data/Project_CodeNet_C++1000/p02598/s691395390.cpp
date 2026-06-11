#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(n);i++)
#define sort_all(x) sort((x).begin(),(x).end())
using ll = long long;
using P = pair<int,int>;



int main() {
	
	
	ll n, k; cin >> n >> k;
	
	vector<ll> a(n); rep(i,n) cin >> a[i];

	int ng = 0;
	int ok = 1000000001;

	while(1){
		int len = (ng + ok) / 2;
		int cnt = 0;
		rep(i,n) cnt += (a[i] + len - 1) / len - 1;
		// cout << cnt << endl;
		if(cnt > k) ng = len;
		else ok = len;
		if(ok == ng + 1){
			cout << ok << endl;
			// cout << ng << endl;
			return 0;
		}
	}

	
	
	// cout << ans << endl;
	
	return 0;
}
