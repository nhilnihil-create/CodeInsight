#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL << 62)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) { 
        os << v[i]; 
        if (i != (int)v.size() - 1) 
            os << " "; 
    } 
    return os; 
} 

int main()
{
    ll X, Y;
    cin >> X >> Y;
    ll ans = 0;
    if (4 - X > 0) ans += (4-X) * 100000;
    if (4 - Y > 0) ans += (4-Y) * 100000;
    if (X == 1 && Y == 1) ans += 400000;
    print(ans);
    return 0;
}