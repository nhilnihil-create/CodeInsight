#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
#define ppp pair<ll,pp >
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rep(i,a,b) for( ll i = a ; i < b ; i+=1 )
#define sz(v) (ll)(v.size())
#define hell (ll)998244353
#define slld(x) scanf("%lld",&x)
ll t=1, tt;
const ll N=1000005, inf=1e18;
void solve(){
	ll n, m, idx;
	vector<pp> ans;
	cin>>n>>m;
	idx=1;
	for(ll i=m;i>=1;i-=2){
		cout<<idx<<" "<<idx+i<<"\n";
		idx++;
	}
	idx=n;
	for(ll i=m-1;i>=1;i-=2){
		cout<<idx-i<<' '<<idx<<"\n";
		idx--;
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   	//cin>>t;
   	tt=t;
    while(t--){
        solve();
        if(t)cout<<"\n";
    }
    return 0 ;
}
