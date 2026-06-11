#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const ll INF=1<<30;

int main(){
	ll n;cin>>n;
	vector<ll> x(n);
	vector<ll> y(n);
	for(ll i = 0; i < n; i++) {
		cin>>x[i]>>y[i];
	}
	ll res = 0;
	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < n; j++) {
			ll ans = 0;
			if (i != j){
				ll dx = x[i] - x[j];
				ll dy = y[i] - y[j];
				for(ll k = 0; k < n; k++) {
					for(ll l = 0; l < n; l++) {
						if (k != l && x[k] - x[l] == dx && y[k] - y[l] == dy){
								ans ++;
						}
					}
				}
				res = max(res,ans);
			}
			

		}
	}
	cout << n - res << endl;
	return 0;
}