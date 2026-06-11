#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

ll solver(ll x, ll c, ll d){
    ll res = x;
    res -= x/c;
    res -= x/d;
    res += x/lcm(c, d);

    return res;
}

int main() {
    ll A, B, C, D, ans = 0;
    cin >> A >> B >> C >> D;

    ans = solver(B, C, D) - solver(A-1, C, D);
    cout << ans << endl;

    return 0;
}