#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
	ll n, i, k;
	cin >> n;
	vector<ll>v(n+1),val(n);
	rep(i,0,n){
		cin >> k;
		val[i] = k;
		v[k]++;
	}
	ll ans = 0;
	rep(i,1,n+1){
		ans += (v[i] * (v[i]-1))/2;
	}
	rep(i,1,n+1){
		k = (v[val[i-1]] * (v[val[i-1]]-1))/2;
		ans -= k;
		ans +=  ((v[val[i-1]]-1 ) * (v[val[i-1]]-2))/2;
		cout << ans << nl;
		ans -=  ((v[val[i-1]]-1 ) * (v[val[i-1]]-2))/2;	
		ans += k;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}

