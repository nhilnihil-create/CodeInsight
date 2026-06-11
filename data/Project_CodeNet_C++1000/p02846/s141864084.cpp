#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    ll t1,t2; cin>>t1>>t2;
    ll a1,a2; cin>>a1>>a2;
    ll b1,b2; cin>>b1>>b2;
    if(t1*a1+t2*a2==t1*b1+t2*b2) cout<<"infinity"<<endl;
    else{
        ll x=t1*a1+t2*a2,y=t1*b1+t2*b2;
        if(a1>b1 && a2>b2) cout<<0<<endl;
        else if(a1<b1 && a2<b2) cout<<0<<endl;
        //else if(a1==b1 || a2==b2) cout<<0<<endl;
        else{
            ll d1=(a1-b1)*t1;
            ll d2=(a2-b2)*t2;
            ll d3=d1+d2;
            if(d1>0 && d3>0){cout<<0<<endl; return 0;}
            if(d1<0 && d3<0){cout<<0<<endl; return 0;}
            ll z=labs(d1)/labs(d3);
            z=2*z+1;
            if(labs(d1)%labs(d3)==0)z--;
            cout<<z<<endl;
            
        }
    }
}