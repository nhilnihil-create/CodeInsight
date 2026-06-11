#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    ll a,b;
    cin>>a>>b;
    ll x=gcd(a,b);
    set<ll> st;
    ll ans=0;
    for(ll i=1;i<=sqrt(x);i++){
        if(x%i==0){
            st.insert(i);
            st.insert(x/i);
        }
    }
    vector<bool> s(st.size(),true);
     for(auto itr = st.begin(); itr != st.end(); ++itr) {
         if(s[distance(st.begin(),itr)])
         ans++;
         else continue;
         for(auto itr2 = next(itr,1);itr2!=st.end();itr2++){
             if(s[distance(st.begin(),itr)]&&gcd(*itr,*itr2)!=1)
             s[distance(st.begin(),itr2)]=false;
         }
    }
    cout<<ans<<endl;
}