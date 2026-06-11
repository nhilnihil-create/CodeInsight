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
	ll n, i, x;
	cin >> n;
	bool ok = 0;
	rep(i,0,n){
		cin >> x;
		if(x%2==0){
			if(x%3 != 0 && x%5 != 0)ok = 1;
		}
	}
	if(ok)cout << "DENIED" << nl;
	else cout << "APPROVED" << nl;
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

