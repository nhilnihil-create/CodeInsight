#include<bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;  
#define ordered_set tree<ll, null_type , less<ll> , rb_tree_tag , tree_order_statistics_node_update> 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define inf 1e18
#define mk make_pair
#define ld long double
#define mod 1000000007
#define fi first
#define se second
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test ll t; cin>>t; while(t--)
int main()
{
    ll n;
    cin>>n;
    ll val=n/2;
    if(n%2==0)
    {
        val--;
    }
    cout<<val<<'\n';
    return 0;
}