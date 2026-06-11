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
ll m;

ll gcdE(ll a, ll b, ll *x, ll *y){
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    ll x1,y1;
    ll gcd=gcdE(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
ll inf=1e12;
ll modI(ll a){
    ll x,y;
    gcdE(a,m,&x,&y);
    return (x+inf*m)%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin>>k;
    if(k%2==0 || k%5==0){
        cout<<-1<<endl;
        return 0;
    }
    if(k%7==0){
        k/=7;
    }
    m=9*k;
    ll num=1;
    ll flag=0;
    for(ll i=1;i<m;i++){
        num=(num*10)%m;
        ll x=modI(num);
        if(x==1){
            flag=i;
            break;
        }
    }
    if(flag) cout<<flag<<endl;
    else cout<<-1<<endl;
}
