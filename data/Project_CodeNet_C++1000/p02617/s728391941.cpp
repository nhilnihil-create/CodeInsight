#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
// #define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)
#define smax(a,b) a=max(a,b)
// #if !defined(ONLINE_JUDGE)
// #include "debugging.h"
// #endif
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

// int const mod = 7340033;
// int const mod = 998244353;
int const mod = 1e9+7;
int power(int a,int b,int m){
    int res = 1;
    while(b){
        if(b&1){
            res = res*a;
            res %= m;
        }
        a=a*a;
        a%=m;
        b=b/2;
    }
    return res;
}

int inverse(int x , int m){
    return power(x,m-2,m);
}

int const N = 2e5+5;
int const inf = 2e9;

vector<int> adj[N];


void solve(){  
    int i,j,l;
	int n;
	cin>>n;
	for(i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		if(u > v) swap(u,v);
		adj[v].pb(u);
	}	
	int ans = 0;
	int k = 0;
	for(i=1;i<=n;i++){
		int x = i*(i+1)/2;
		ans = ans + x;
		int z = 0;
		for(auto y:adj[i]){
			z = z + y;
		}
		ans = ans - z - k;
		k += z;
	}
	cout<<ans<<endl;
}           


int32_t main(){
    IOS;
    int t;
    t = 1;
    // precompute();
    // cin>>t;
    for(int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}


/*

10
3 5
5 7
8 9
1 9
9 10
4 8
4 7
6 10
2 7

1  2  3  4   5   6    7     8  9  10
4  4  3  2   1   0    0     0  0   0 

1  3  6  10  12  18   28-




*/