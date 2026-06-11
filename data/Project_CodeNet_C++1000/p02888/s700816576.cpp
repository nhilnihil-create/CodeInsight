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
	ll n, i, ans = 0, lb, hb, mid, j;
	cin >> n;
	vector<ll>v(n);
	for(i = 0; i < n; i++)cin >> v[i];
	sort(all(v));
	rep(i,0,n-2){
		rep(j,i + 1,n - 1){
			ll cur = v[i] + v[j], in;
			if(v[j + 1] >= cur)
				continue;
			if(v[n - 1] < cur){
				ans += n - j - 1;
				continue;
			}
			lb = j + 1, hb = n - 1;
			while(lb <= hb){
				mid = (lb + hb) / 2;
				if(v[mid] < cur){
					in = mid;
					lb = mid + 1;
				}
				else
					hb = mid - 1;
			}
			ans += in - j;
		}
	}
	cout << ans << nl;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
	// cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
