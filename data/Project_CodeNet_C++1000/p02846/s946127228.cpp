#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
using namespace std;
const ll mod=1e9+7;

main(){
    ll t1,t2,a1,a2,b1,b2,n,ans=0;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    ll c1=a1-b1,c2=a2-b2;
    ll d1=c1*t1;
    ll d2=c2*t2;
    if(d1>0&&d2<0){
        d2=labs(d2);
        ll f=d2-d1;
        if(f==0)cout<<"infinity";
        else if(f<0)cout<<"0";
        else if(f>0){
            if(d1%f==0)cout<<2*(d1/f);
            else if(d1%f!=0)cout<<2*(d1/f)+(ll)1;
        }
    }
    else if(d2>0&&d1<0){
        d1=labs(d1);
        ll f=d2-d1;
        if(f==0)cout<<"infinity";
        else if(f<0)cout<<"0";
        else if(f>0){
            if(d1%f==0)cout<<2*(d1/f);
            else if(d1%f!=0)cout<<2*(d1/f)+(ll)1;
        }
    }
    else cout<<"0";
}
