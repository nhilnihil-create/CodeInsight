#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define db double
#define el "\n"
#define ld long double
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n;i>=0;i--)
#define rep_a(i,a,n) for(int i=a;i<n;i++)
#define tr(ds, it) for(auto it=ds.begin(); it!=ds.end(); it++)
#define rtr(ds, it) for(auto it=ds.rbegin(); it!=ds.rend(); it--)
#define all(ds) ds.begin(), ds.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef priority_queue <int> pq;
typedef vector< long long > vi;
typedef pair<long long, long long> ii;
#define o_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>

#define Mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    fastio;
//	#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r" , stdin);
//    freopen("output.txt", "w" , stdout);
//    #endif
    ll n, m;
    cin >> n >> m;
    
    int x = 2 * ((m + 1) / 2), y = 1, z = x + 1, w = 2 * m + 1;
    
    while (y < x) {
    	cout << y << " " << x << "\n";
    	y++,x--;
	}
	
	
	
	while (z < w) {
		cout << z << " " << w << "\n";
		z++,w--;
	}
	
	//code
	return 0;
}
