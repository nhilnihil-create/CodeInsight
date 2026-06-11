#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;
 
// /////////////////////////////////////////////
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
// ////////////////////////////////
 
#define int long long

void solve(){

	int n;
	cin>>n;
	int root = sqrt(n);
	int ans = 1;
	set<int> s;
	if(n==2){

		cout<<1<<endl;
		return ;
	}
	for(int i = 2 ; i <= root ; ++i){

		int x = n;
		while(x%i==0){

			x/=i;
		}

		if(x%i==1){
			++ans;
			s.insert(i);
		}
	}
	//debug(ans);
	root = sqrt(n-1);
	--n;
	for(int i = 2 ; i <= root ; ++i){

		if(n%i==0){
			ans++;
			if(s.find(i)!=s.end())
				--ans;
			if(n/i!=i){
				++ans;
				if(s.find(n/i)!=s.end())
					--ans;
			}
		}
	}
	ans++; // for n-1


	cout<<ans<<endl;
}
 
 
signed main(){
 
    fast;
    int t = 1;
    //cin>>t;
    for(int i = 1 ; i <= t; ++i){
 
    	solve();
    }
}