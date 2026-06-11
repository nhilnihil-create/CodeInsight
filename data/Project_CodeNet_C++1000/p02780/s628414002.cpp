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
	ll n, i, k, sum = 0;
	cin >> n >> k;
	vector<ll>pre(n+2);
	rep(i,1,n+1){
		cin >> pre[i];
		pre[i] += pre[i-1];
	}
	rep(i,k,n+1){
		sum = max(sum , pre[i] - pre[i-k]);
	}
	cout << fixed << setprecision(10) << (double)(1.0 * sum + k)/(2.0) << nl;
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

