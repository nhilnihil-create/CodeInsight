#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

ll a[100002], b[100002];

int main(){
	fastio;
	int n; cin >> n;
	for(int i = 0; i < n + 1; ++ i) cin >> a[i];
	for(int i = 0; i < n; ++ i) cin >> b[i];
	ll ans = 0;
	for(int i = 0; i < n; ++ i){
		if(b[i] > a[i]){
			b[i] -= a[i];
			ans += a[i];
			a[i] = 0;
		}
		else{
			ans += b[i];
			a[i] -= b[i];
			b[i] = 0;
		}

		if(b[i] > a[i + 1]){
			ans += a[i + 1];
			b[i] -= a[i+1];
			a[i+1] = 0;
		}
		else{
			ans += b[i];
			a[i+1] -= b[i];
			b[i] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}

