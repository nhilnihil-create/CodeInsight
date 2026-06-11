#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    sort(all(a));
  	ll k = n, l = 0;
	if(a[n-1] >= 0){
    	k = lower_bound(all(a),0) - a.begin(); // k<0
    	l = n-k; // l>=0
    }
  
    if(k == 0){ k++; l--; }
    else if(l == 0){ k--; l++; }

    vector<vector<ll>> ans(n,vector<ll>(2,0));
  
    ans[0][0] = a[0]; // min
  
    rep(i,l-1){
        ans[i][1] = a[n-2-i];
        ans[i+1][0] = ans[i][0] - ans[i][1];
    }
  	
    	ans[l-1][0] = a[n-1]; // max
    	if(l > 1) ans[l-1][1] = ans[l-2][0] - ans[l-2][1];
  		else ans[l-1][1] = a[0];
    	ans[l][0] = ans[l-1][0] - ans[l-1][1];
  
    rep(i,k-1){
        ans[l+i][1] = a[1+i];
        ans[l+i+1][0] = ans[l+i][0] - ans[l+i][1];
    }

    cout << ans[n-1][0] << endl;
    rep(i,n-1) cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}