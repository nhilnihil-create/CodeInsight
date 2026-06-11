#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back


ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

vector<pair<ll,ll>> pfact(ll n)
{
    vector<pair<ll,ll>> pf;
    ll t = n, cnt;
    
    for(ll i=2; i*i<=t; ++i) {
        cnt = 0;
        if(t % i != 0) continue;
        while(t % i == 0) {
            t /= i;
            ++cnt;
        }
        pf.pb(make_pair(i, cnt));
    }
    
    if(t != 1) pf.pb(make_pair(t, 1));
    
    return pf;
}


int main()
{
    ll A, B;
    cin >> A >> B;

    ll G = gcd(A, B);
    auto P = pfact(G);
    PR(SZ(P)+1);

    return 0;
}

/*



*/