#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll f(ll n, ll c, ll d){
    ll sum=n, lcm;
    lcm = c/__gcd(c,d)*d;
    sum -= n/c;
    sum -= n/d;
    sum += n/lcm;
    return sum;
}

int main(void)
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout << f(b,c,d)-f(a-1,c,d) << endl;
    return 0;
}