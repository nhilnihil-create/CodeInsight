#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define double          long double
#define pb              push_back
#define mp              make_pair
#define pi              pair<int,int>
#define vtiii           vector<tuple<int,int,int>>
#define vi              vector<int>
#define vpii			vector<pair<int,int>>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 	
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


void solve(){
	string s;int q,t,f,nf=0;cin>>s>>q;char c; string str = "";
	while(q--){
		cin>>t;
		if(t==1){
			++nf;
		}else{
			cin>>f>>c;
			if(f==1){
				if(nf&1){
					s.pb(c);
				}else{
					str.pb(c);
				}
			}else{
				if(nf&1){
					str.pb(c);
				}else{
					s.pb(c);
				}
			}
		}
	}
	reverse(str.begin(),str.end());
	for(char c : s) str.pb(c);
	if(nf&1){
		reverse(str.begin(),str.end());
	}	
	cout<<str;
}	
 
int32_t main(){	
	FIO;
 	//w(x)
	solve();
	return 0;
}