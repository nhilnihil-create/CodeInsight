#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

//最大公約数を求める関数
ll lcm(ll a,ll b){
    ll c,d,e;
    c=max(a,b);
    d=min(a,b);
    while(1){
        c=c%d;
        if(c==0){
            break;
        }
        e=d;
        d=c;
        c=e;
    }
    return a*b/d;
}
int main(){
    ll n,m;
    cin >> n >> m;
    vector <ll> a(n);
    rep(i,n) cin >> a[i];

    ll sk;
    sk=1;
    int n2;
    n2=0;
    ll n3;
    n3=a[0];


    while(n3%2==0){
        n3/=2;
        ++n2;
        if(n3==0) break;
    }

    ll w;
    w=ll(pow(2,n2));

    rep(i,n){
        sk=lcm(sk,a[i]/2);
        if(a[i]%w!=0){
           sk=-1;
           break; 
        }
        if(sk>m){
            sk=-1;
            break;
        }
    }
    //cout << sk << endl;
    int n4;
    n4=0;
    ll sk2;
    sk2=sk;
    while(sk2%2==0){
        sk2/=2;
        ++n4;
        if(sk2==0) break;
    }
    if(n2!=n4+1){
        sk=-1;
    }
    ll ans;
    if(sk==-1){
        cout << 0 << endl;
    }
    else{
        ans=(m-sk)/(2*sk)+1;
        cout << ans << endl;
    }

    

    return 0;
}