#include <bits/stdc++.h>
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define p_b push_back
#define all(c)              c.begin(), c.end()
using namespace std;
typedef long long ll; //printf("%lld ", ll); to out put long
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const double eps = 1e-6;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
bool ODD(ll O) {return (O % 2 != 0);}
ll gcd(ll a, ll b) {return __gcd(a , b);}
ll lcm(ll a, ll b) {return a * b / gcd(a , b);}
int dx[] = {1, 0, -1 ,0 , -1 , 0};
int dy[] = {0, 1, 0, -1 , -1 , 0};
ll power (ll x, ll y) {
    if(y == 0) return 1;
    if(ODD(y)) return x * power(x , y / 2) * power(x , y / 2);
    return power(x , y / 2) * power(x , y / 2);
}
/*------ never give up --------*/

int main () {
    int t = 1;
    //cin >> t;
    while(t--) {
        ll a, b, c ,d;
        cin >> a >> b >> c >> d;
        ll n = b - a + 1ll;
        n -= (b / c) - ((a - 1) / c);
        n -= (b / d) - ((a - 1) / d);
        n += (b / lcm(c , d)) - ((a - 1) / lcm(c , d));
        cout << n;
    }
    return 0;
}
