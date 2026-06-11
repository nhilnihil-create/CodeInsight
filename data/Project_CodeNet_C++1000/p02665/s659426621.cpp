#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD  1000000007
#define ll long long
#define int long long
#define INF 1e18
#define ar array
#define MAX 1000004
#define wt(x) int x;cin>>x;while(x--)

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> pbds;

void  c_p_c(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
#endif
 
}
ll power(ll a,ll b,int mod){
    a=a%mod;
    if(a==0){
        return 1;
    }
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
 }
 

 int32_t main() {

c_p_c();
int n;
cin>>n;
vector<ll>a(n+1);
for(int i=0;i<=n;i++)cin>>a[i];
    if(a[0]>=2){
        cout<<-1;
        return 0;
    }
    
        vector<ll>pref(n+2);
        for(int i=1;i<=n+1;i++){
            pref[i]=pref[i-1]+a[i-1];
        }
        vector<ll>n_leaf(n+1);
        n_leaf[0]=1-a[0];
        for(int i=1;i<=n;i++){
            n_leaf[i]=(2LL *n_leaf[i-1])-a[i];
            n_leaf[i]=min(n_leaf[i],(pref[n+1]-pref[i+1]));
            if(n_leaf[i]<0){
                cout<<-1;
                return 0;
            }
        }
    
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=n_leaf[i]+a[i];
    }
    cout<<ans;


return 0;

}
 


   

        

