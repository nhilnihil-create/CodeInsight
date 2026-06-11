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
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(void)
{
    ll n;
    cin >> n;
    vector<P> ab(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ab[i] = {b, a};
    }
    sort(all(ab));
    bool can = true;
    ll tmp = 0;
    rep(i,n){
        tmp += ab[i].second;
        if(tmp > ab[i].first) can = false;
    }
    if(can) puts("Yes");
    else puts("No");
    return 0;
}