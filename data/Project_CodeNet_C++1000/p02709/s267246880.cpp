#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<random>

//#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define ALL(v) (v).begin() , (v).end()
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;

/////////////////////////////////////////////

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

////////////////////////////////

#define int long long

void solve(){

	int n;
	cin>>n;
	vector<pair<int,int>> a(n+1);
	for(int i = 1 ; i <= n ; ++i){
		cin>>a[i].ff;
		a[i].ss = i;
	}

	sort(a.begin()+1,a.end() , greater<pair<int,int>>());

	int dp[n+1][n+1];
	memset(dp , 0 , sizeof dp);

	for(int i = 1 ; i <= n ; ++i){

		int x = a[i].ff;
		int pos = a[i].ss;
		for(int j = 0 ; j <= i ; ++j){

			int val = 0;
			if(j > 0)
				val = dp[i-1][j-1] + x*(pos - j);

			if(j!=i)
				val = max(val , dp[i-1][j] + x*(n - (i - j - 1)-pos));

			dp[i][j] = val;

			//debug(dp[i][j] , i , j);
		}
	}

	int ans = *max_element(dp[n] , dp[n]+n+1);

	cout<<ans<<endl;

}

signed main(){

    fast;
    //freopen("output.txt" , "w" , stdout);
    int t = 1;
   // cin>>t;
    for(int i = 1 ; i <= t; ++i){

    	solve();
    }
}
