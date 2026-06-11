#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    ll n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    ll l[k],r[k];
    rep(0,i,k){
        l[i]=-1;
        r[i]=-1;
    }
    ll cl=0,cr=0;
    rep(0,i,n){
        string s0=s.substr(i,1);
        if(cl==0){
            if(s0=="o"){
                l[cl]=i;
                ++cl;
            }
        }else{
            if(cl>=k)break;
            if(l[cl-1]+c<i && s0=="o"){
                l[cl]=i;
                ++cl;
            }
        }
        //cout<<s0<<endl;
        //cout<<l[cl-1]<<endl;
    }
    rep(0,i,n){
        string s0=s.substr(n-1-i,1);
        ll x=n-1-i;
        ll ccr=k-1-cr;
        if(cr==0){
            if(s0=="o"){
                r[ccr]=x;
            //cout<<l[ccr]<<endl;
                ++cr;
            }
        }else{
            if(cr>=k)break;
            if(r[ccr+1]-c>x && s0=="o"){
                r[ccr]=x;
        //cout<<l[ccr]<<endl;
                ++cr;
            }
        }
        //cout<<l[ccr]<<endl;
    }
    rep(0,i,k){
        if(r[i]!=-1 && l[i]!=-1 && r[i]==l[i]){
            cout<<r[i]+1<<endl;
        }
    }
}
