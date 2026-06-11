
// Problem : E - Count Median
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n'
#define debug_arr(a , n) for(ll i = 0 ; i < n ; i++)cout << a[i] << " "
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 1000000000
#define mod 1000000007

const ll max_n = 1e5 + 9;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
int main()
{
    ll n;
    cin >> n;
    
    vector<pair<ll,ll>> a(n) , b(n);
    for(ll i = 0 ; i < n ; i++){
    	cin >> a[i].ff >> a[i].ss;
    	b[i] = a[i];
    }
    
    sort(all(a));
    sort(all(b) , [](pair<ll,ll> x , pair<ll,ll> y){
    	return x.ss < y.ss;
    });
    
    
    if(n % 2 == 1){
    	ll start = a[n/2].ff , end = b[n/2].ss;
    	// debug(start);
    	// debug(end);
    	cout << end - start + 1 << endl;
    }
    else{
    	ll start = a[n/2].ff + a[n/2 - 1].ff , end = b[n/2].ss + b[n/2-1].ss;
    	// debug(start);
    	// debug(end);
    	cout << end - start + 1 << endl;
    }
    return 0;
}