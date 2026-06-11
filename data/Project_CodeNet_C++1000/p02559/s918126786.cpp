#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e9
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define pb push_back
#define all(s) s.begin(),s.end()
#define pie 3.14159265358979323846
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define gcd __gcd
#define con continue
#define pii pair<ll,ll>
const ll N=5e5+6;
ll bit[N];
void update(ll idx,ll val){
   for(ll i=idx;i<N;i+=i&(-i)){
      bit[i]+=val;
   }return;
}
ll query(ll idx){
   ll res=0;
   if(idx==0)return 0;
   for(ll i=idx;i>0;i-=i&(-i)){
      res+=bit[i];
   }return res;
}
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
         ll n,q,x,l,r;cin>>n>>q;
         ll a[n+1];
         for(ll i=1;i<=n;i++){
            cin>>a[i];
            update(i,a[i]);
         }
         while(q--){
            cin>>x;
            if(x){
               cin>>l>>r;l++;r++;
               cout<<query(r-1)-query(l-1);
               cout<<"\n";
            }
            else{
               cin>>l>>x;l++;
               update(l,x);
            }
         }
    }
}
