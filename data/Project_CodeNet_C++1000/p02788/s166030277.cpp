#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353

vector<vector<ll>> b(210000,vector<ll>(2,0));

bool isOK(ll index, ll key){ 
    if (b.at(index).at(0) > key) return true; 
    else return false;
}

ll binse(ll key, ll sizem){ //sizem番目まで二分探索
	ll left = -1;
	ll right = sizem;
	while (right-left>1){
		ll mid = left+(right-left)/2;
		if (isOK(mid, key)) right = mid;
		else left = mid;
	}
	return right;
}

int main(){
	ll n, d, a, x, h; cin >> n >> d >> a;
	REP(i,n){
		cin >> x >> h;
		b[i][0] = x;
		b[i][1] = (h+a-1)/a;
	}
	sort(b.begin(), b.begin()+n);
	vector<ll> cnter(n+1,0);
	ll ans = b[0][1];
	cnter[0] = b[0][1];
	cnter[binse(b[0][0]+2*d,n)] -= b[0][1];
	FOR(i,1,n-1){
		cnter[i] += cnter[i-1];
		ll ky = b[i][0]+2*d;
		ll diff = b[i][1]-cnter[i];
		if (diff>0){
			ans += diff;
			cnter[i] += diff;
			cnter[binse(ky,n)] -= diff;
		}
		//cout << i << " " << diff << " " << cnter[i] << " " << binse(ky,n) << endl;
	}
	cout << ans << endl;
}