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
int h1,m1,h2,m2,k;
cin>>h1>>m1>>h2>>m2>>k;
int tot1=(h1*60)+m1;
int tot2=(h2*60)+m2;
int rem=tot2-k;
cout<<abs(tot1-rem)<<"\n";

    

return 0;

}
 
