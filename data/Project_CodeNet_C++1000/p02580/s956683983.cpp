#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll h,w,m;
	cin >> h >> w >> m;
	vector<ll> row(h,0),col(w,0);
	set<pair<ll,ll>> s;
	ll mr=0,mc=0;
	for(ll i=1;i<=m;i++){
		  ll a,b;
		  cin >> a >> b;
		  row[a-1]++;
		  col[b-1]++;
		  s.insert({a-1,b-1});
		  mr = max(mr,row[a-1]);
		  mc = max(mc,col[b-1]);
	}
	ll dec_points = 0;
	for(auto i : s){
		if(row[i.first] == mr && col[i.second] == mc)
		dec_points++;
	}
	ll mrows = count(row.begin(),row.end(),mr);
	ll mcols = count(col.begin(),col.end(),mc);
	cout << mr + mc - (mrows*mcols == dec_points) << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

