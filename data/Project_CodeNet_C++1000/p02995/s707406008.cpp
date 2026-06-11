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

ll lcm(ll a, ll b){
    return abs(a) / __gcd(a,b) * abs(b);
}

int main(void)
{
    ll a,b,c,d,x;
    cin>>a>>b>>c>>d;
    x = (b/c - (a-1)/c) + (b/d - (a-1)/d) - (b/(lcm(c,d)) - (a-1)/(lcm(c,d)));
    cout << b-a+1-x << endl;
    return 0;
}