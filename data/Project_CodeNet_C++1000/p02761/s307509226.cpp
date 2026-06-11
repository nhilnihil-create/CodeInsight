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
	ll n,m = 0,i,a[5];
	a[1] = a[2] = a[3] = -1;
	cin >> n >> m;
	bool ok = 0;
	while(m--){
		ll x,y;
		cin >> x >> y;
		if(ok)continue;
		if(x == 1 && y == 0 && n != 1){
			ok = 1;
			continue;
		}
		if(a[x] != -1){
			if(a[x] != y){ok = 1 ;continue;}
		}
		a[x] = y;
	}
	if(!ok && n == 1){
		cout << max(a[1] , 0LL) << nl;
		return ;
	}
	if(ok) cout << -1 << nl;
	else {
		rep(i,1,n+1){
			if(i == 1){
				if(a[i] == -1)cout << 1;
				else cout << a[i];
				continue;
			}
			if(a[i] == -1)cout << 0;
			else cout << a[i];
		}
	}	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	// cin >> t;
	for(ll i = 1; i <= t; i++){
		doit();
	}
}
