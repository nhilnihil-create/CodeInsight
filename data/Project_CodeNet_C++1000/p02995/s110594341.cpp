#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll> >;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

ll a, b, c, d;

ll gcd(ll a, ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}


int main(){
    cin >> a >> b >> c >> d; a--;
    ll t1, t2;
    t1 = (b/c); t2 = (a/c);
    ll x = t1 - t2;
    t1 = (b/d); t2 = (a/d);
    ll y = t1 - t2;
    ll l = lcm(c, d);
    t1 = (b/l); t2 = (a/l);
    ll z = t1 - t2;

    cout << (b-a) - (x+y-z) << endl;
    return 0;
}