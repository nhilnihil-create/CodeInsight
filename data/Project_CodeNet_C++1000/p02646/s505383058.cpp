#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll A,V,B,W,T;
	cin >> A >> V >> B >> W >> T;
	if(V>W){
		if(abs(B-A) > (V-W)*T){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" <<endl;
		}
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}