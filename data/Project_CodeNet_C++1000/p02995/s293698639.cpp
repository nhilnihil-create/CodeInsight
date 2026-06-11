#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b){
    if(a%b==0){
        return b;
    }
    ll t = a;
    a = b;
    b = t%b;
    return gcd(a,b);
}

ll lcm(ll c, ll d){
    return c*d/gcd(max(c,d),min(c,d));
}

int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll Cd,Dd,CDd,CDl;
    Cd = b/c-(a-1)/c;
    Dd = b/d-(a-1)/d;
    CDl = lcm(c,d);
    CDd = b/CDl - (a-1)/CDl;
    ll ans;
    ans = (b-a+1) - (Cd+Dd-CDd);
    cout<<ans<<endl;

    return 0;
}