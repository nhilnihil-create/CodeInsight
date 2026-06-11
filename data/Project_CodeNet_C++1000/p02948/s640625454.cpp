#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
void solve(){
	ll n,m,res=0;
	cin>>n>>m;
	vector<p2> v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i].second>>v[i].first;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	set<ll> s;
	for(ll i=0;i<m;i++)
		s.insert(i);
	for(ll i=0;i<n;i++){
		auto it=s.lower_bound(m-v[i].second+1);
		if(s.empty()||it==s.begin())
			continue;
		s.erase(prev(it,1));
		res+=v[i].first;
	}
	cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    clock_t z=clock();
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++){
        solve();
    }
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}
