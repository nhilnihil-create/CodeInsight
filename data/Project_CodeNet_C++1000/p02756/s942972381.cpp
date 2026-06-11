#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    string s;
    cin>>s;
    ll q;
    cin>>q;
    bool t=true;
    vector<char>s1,s2;
    rep(0,i,q){
        ll q0;
        cin>>q0;
        if(q0==1)t=!t;
        if(q0==2){
            ll f;
            char c;
            cin>>f>>c;
            if(t){
                if(f==1)s1.pb(c);
                if(f==2)s2.pb(c);
            }else{
                if(f==1)s2.pb(c);
                else s1.pb(c);
            }
        }
    }
    ll n1=s1.size(),n2=s2.size();
    if(t){
        rep(0,i,n1)cout<<s1[n1-1-i];
        cout<<s;
        rep(0,i,n2)cout<<s2[i];
    }else{
        rep(0,i,n2)cout<<s2[n2-1-i];
        rep(0,i,s.size())cout<<s[s.size()-1-i];
        rep(0,i,n1)cout<<s1[i];
    }
}