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
const int INF=1<<30;

int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	vector<ll> cnt(n,0);
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		if (a[i] != 0){
			if (cnt[a[i] - 1] <= cnt[a[i]]){
				cout << 0 << endl;
				return 0;
			}
			ans *= (cnt[a[i] - 1] - cnt[a[i]]);
			ans %= mod;
			cnt[a[i]]++;
		}
		else{
			cnt[0]++;
		}
	}
	if (cnt[0] == 1){
		ans *= 3;
		ans %= mod;
	}
	else{
		ans *= 6;
		ans %= mod;
	}
	for(int i = 0; i < n; i++) {
		if (cnt[i] > 3){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}