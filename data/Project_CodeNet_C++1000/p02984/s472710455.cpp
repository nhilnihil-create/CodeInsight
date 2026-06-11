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
	vector<ll>v(n), ans(n);
	for(i = 0; i < n; i++)cin >> v[i];
	rep(i,0,n){
		if(i&1)
			ans[0] -= v[i];
		else
		   	ans[0] += v[i]; 
	}
	rep(i,1,n){
		ans[i] = 2 * v[i - 1] - ans[i-1];
	}
	rep(i,0,n){
		cout << ans[i] << " ";
	}
}
int main() {
#ifndef ONLINE_JUDGE
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
