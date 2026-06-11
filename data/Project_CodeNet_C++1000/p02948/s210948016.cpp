#include <bits/stdc++.h>
//v.erase(unique(v.begin(),v.end()),v.end());
 
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
 
typedef double ld;
typedef long long ll;
const ll N = 100500;
const ll mod = 1000000007;
const ll INF = 1e+9;
using namespace std;
//using namespace __gnu_pbds;
 
//typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif

vector <pair <int, int>> xd[N];    

void solve(){
	int n, k; cin >> n >> k;

	for(int i = 0; i < n ;i++){
		int a, b; cin >> a >> b;
		xd[a].push_back({-b, i + 1});
	}
	//for(int i = 0; i < N; i++) sort(xd[i].rbegin(), xd[i].rnd());
	set <pair <int, int>> s;
	ll ans = 0; 
	for(int i = 1; i <= k; i++){
		for(auto x: xd[i]) s.insert(x);
		pair <int, int> p = *(s.begin());
		ans += (-p.ff);
		s.erase(p);
	}

	cout << ans << endl;
	
}
 
int main(){
    
    int tc = 1;
    //cin >> tc;	
	
    while(tc--) solve();
    
    return 0;
}