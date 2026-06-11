#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1e5)

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
    ll M, D;
    cin >> M >> D;
    if (D < 22) print(0);
    else {
        ll cnt = 0;
        for(ll i = 22; i <= D; i++) {
            if (i / 10 < 2 || i%10 < 2) continue;
            ll tmp = (i/10) * (i%10);
            if (tmp <= M) cnt++;
            
        }
        print(cnt);
    }
    return 0;
}