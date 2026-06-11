#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll ans=b-b/c-b/d+b/lcm(c,d);
    ans-=(a-1)-(a-1)/c-(a-1)/d+(a-1)/lcm(c,d);

    cout<<ans<<endl;
}

