#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_mset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fr(i,a,b) for (int i=(a); i<(b);++i)
#define frr(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define vi deque<int>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define F first
#define S second
#define pii pair<ll,ll> 
#define rev(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.begin(),a.end(),greater<int>())
#define sz(a) (int)a.size()
#define endl '\n'
#define po(a,b) (ll)(pow(a,b)+0.5)
#define print(a) for(auto x:a)cout<<x<<" ";cout<<endl;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
//#define double long double
const ll M=1e9+7;
const int MX=1e5+1;
     
int main()
{     
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Fast
 int tt=1;
 //cin>>tt;
 while(tt--){
        int x;
        cin>>x;
        cout<<360/__gcd(360,x);
}}

