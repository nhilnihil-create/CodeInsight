#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define ff first
#define ss second
#define dd double
#define mod 1000000007

template<class K,class other=null_type,class cmp=less<K>> using ordered_set=tree<K,other,
cmp, rb_tree_tag, tree_order_statistics_node_update>;

inline ll md(ll x){
    return x<mod?x:x%mod;
}

ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    ll x_=power(x,y/2);
    if(y & 1){
        return md(md(x_*x_)*md(x));
    }
    else{
        return md(x_*x_);
    }
}

ll mod_inverse(ll x){
    return power(x,mod-2);
}
const ll N=1e6+1;
ll spf[N];

void prime(){
    for(ll i=1;i<=N;i++){
        spf[i]=i;
    }
    for(ll i=4;i<=N;i+=2){
        spf[i]=2;
    }
    for(ll i=2;i*i<=N;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=N;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime();
    ll n;
    cin>>n;
    ll arr[n];
    REP(i,n){
        cin>>arr[i];
    }
    ll x=arr[0];
    FOR(i,1,n){
        x=__gcd(x,arr[i]);
    }
    if(x!=1){
        cout<<"not coprime"<<endl;
    }
    else{
        map<ll,ll> m;
        ll flag=1;
        REP(i,n){
            ll x=arr[i];
            while(x>1){
                ll y=spf[x];
                if(m[y]!=0 && m[y]!=i){
                    flag=0;
                    break;
                }
                else{
                    m[y]=i;
                }
                x/=y;
            }
            if(!flag){
                break;
            }
        }
        if(!flag){
            cout<<"setwise coprime"<<endl;
        }
        else{
            cout<<"pairwise coprime"<<endl;
        }
    }
}
