#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 10002

ll ara[mx];

ll fn(ll a,ll b,ll c){
    if(a==b && b==c)    return 1;
    if(a!=b && b==c)    return 3;
    if(a==b && b!=c)    return 3;
    return 6;
}

main(){
//read;

ll cnt = 0;

for(ll i = 1; i<mx; i++){
    for(ll j = i; j<mx; j++){
        for(ll k = j; k<mx; k++){
            ll a = i*i+j*j+k*k+i*j+j*k+k*i;
            if(a>=mx)   break;
            ara[a]+=fn(i,j,k);
        }
    }
}

ll n;
cin>>n;
for(ll i = 1; i<=n; i++)
    cout<<ara[i]<<endl;


return 0;
}
