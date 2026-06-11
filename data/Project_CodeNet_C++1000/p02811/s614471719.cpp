#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <chrono> 
using namespace std::chrono;
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_mset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fr(i,a,b) for (ll i=(a); i<(b);++i)
#define frr(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define vi vector<ll>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define F first
#define S second
#define pii pair<ll,ll> 
#define rev(a) reverse(a.begin(),a.end())
#define srt(a,k) sort(a,a+k,greater<ll>())
#define rsrt(a) sort(a.begin(),a.end(),greater<ll>())
#define sz(a) (ll)a.size()
//#define endl "\n"
#define po(a,b) (ll)(pow(a,b)+0.5)
#define double long double
#define print(a) for(auto x:a)cout<<x<<" ";cout<<endl;
#define setbits(a) __builtin_popcount(a)
const ll M=1e9+7;
const ll mxx=3001;

int main()
{  


  ll k,x;
  cin>>k>>x;
  if(500*k>=x)cout<<"Yes";
  else cout<<"No";
}

