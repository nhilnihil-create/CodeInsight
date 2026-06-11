//raja1999

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define int ll

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


//std::ios::sync_with_stdio(false);
int vis[3005][30065],dp[3005][3005],a[3005],n,s;
int compute(int rem,int pos){
	if(rem<0){
		return 0;
	}
	if(pos==n){
		if(rem==0){
			return 1;
		}
		return 0;
	}
	if(vis[rem][pos]){
		return dp[rem][pos];
	}
	int val,val1;
	vis[rem][pos]=1;
	dp[rem][pos]=0;
	val=compute(rem-a[pos],pos+1);
	val1=compute(rem,pos+1)*2LL;
	val+=val1;
	val%=mod;
	dp[rem][pos]=val;
	return val;
}
main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t,t1;
	t=1;
//	cin>>t;
	t1=t;
	while(t--){
//		cout<<"Case #"<<t1-t<<": ";
		int val,ans,i;
		cin>>n>>s;
		rep(i,n){
			cin>>a[i];
		}
		val=compute(s,0);
		cout<<val<<endl;
	}
	return 0;
} 
