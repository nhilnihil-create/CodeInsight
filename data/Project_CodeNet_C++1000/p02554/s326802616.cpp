#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define sc second
#define INF 3000000000
#define SINF 2*(1e18)
#define inf -10000000
#define pb push_back
#define forr(i,p,n) for(int i=p;i<n;i++)
#define mpk make_pair
#define upb(a,s) upper_bound(a.begin(),a.end(),s)
#define lwb(a,s) lower_bound(a.begin(),a.end(),s)
#define mem(a,val) memset(a,val,sizeof a)
#define cc continue
#define eb emplace_back
#define bb break
#define mostbit(n) 32-__builtin_clz(n)-1
#define time_to_forget cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
ll mod=1e9+7;
ll fastpow(ll a,ll b){
  ll pos=1;
  forr(i,0,b){
    pos*=a;
    pos%=mod;
  }
  return pos;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie();
    ll a,b,c,d,n,t,m,k;
    while(cin>>n){
      ll ans=fastpow(10,n)-fastpow(9,n)-fastpow(9,n)+fastpow(8,n);
      ans%=mod;
      ans=(ans+mod)%mod;
      cout<<ans<<endl;
    }
}
