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
#define o_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define graph vector<vi>

const ll mod = 1000000007;
ll po(ll x, ll n ){ 
  ll ans=1;
     while(n>0){
       if(n&1) ans=(ans*x)%mod;
       x=(x*x)%mod;
       n/=2;
     }
     return ans;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T=1;
  //cin >> T;
  while(T--){
    string s;
    ll k, cnt, f=0,g;
    cin>>s>>k;
    ll ant, ans=0;
    vi v;
    rep(i,s.length()){
      //cout<<i<<" ";

      char c=s[i];
      cnt=0;
      while(s[i]==c){
        cnt++;
        i++;
        if(i==s.length()) break;
      }
      i--;
      //cout<<i<<el;
      v.pb(cnt);
    }
    // rep(i,v.size()) cout<<v[i]<<" ";
    // cout<<el;
    if(v[0]==s.length()){
      cout<<(k*(s.length()))/2<<el;
      return 0;
    }
    else if(s[0]==s[s.length()-1]){
      if(v[0]%2 && v[v.size()-1]%2){
        ans+=(v[0]+v[v.size()-1])/2;
        f=1;
        g=ans;
      }
      else{
        ans+=v[0]/2+v[v.size()-1]/2;
      }
      //cout<<ans<<el;
    }
    else ans+=v[0]/2+v[v.size()-1]/2;
    //cout<<ans<<el;
    rep_a(i,1,v.size()-1) ans+=v[i]/2;
    if(!f) cout<<k*ans<<el;
    else{
      cout<<k*ans-g+v[0]/2+v[v.size()-1]/2<<el;
    }

  }

  return 0;
}