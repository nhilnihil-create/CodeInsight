#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int main(){
    ll n,P[200001],I[200001];
    cin>>n;
    rep(i,n) cin>>P[i],I[P[i]]=i+1;
    ll ans=0;
    set<ll> A;
    for(ll i=n;i>0;i--){
        if(i==n){
            A.insert(I[n]);
            continue;
        }
        ll l,r,ll,rr;
        l=*--A.lower_bound(I[i]),r=*A.upper_bound(I[i]);
        if(*A.begin()>I[i]) l=0;
        if(*A.rbegin()<I[i]) r=n+1;
        if(l!=0){
            ll=*--A.lower_bound(l);
            if(*A.begin()==l) ll=0;
        }
        else ll=0;
        if(r!=n+1){
            rr=*A.upper_bound(r);
            if(*A.rbegin()==r) rr=n+1;
        }
        else rr=n+1;
        if(l!=0){
            if(r!=0) ans+=(r-I[i])*(l-ll)*i;
            else  ans+=(n-I[i])*(l-ll)*i;
        }
        if(r!=n+1){
            if(l!=0) ans+=(I[i]-l)*(rr-r)*i;
            else  ans+=I[i]*(rr-r)*i;
        }
        //cout<<ll<<" "<<l<<" "<<r<<" "<<rr<<"\n";
        A.insert(I[i]);
    }
    cout<<ans<<"\n";
}