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
static const ll dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

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
    ll M;
    cin >> M;
    ll cnt1 = 0;
    ll cnt2 = 0;
    rep(i, M) {
        ll d,c;
        cin >> d >> c;
        cnt1 += d*c;
        cnt2 += c;
    }
    print(cnt2-1 + (cnt1-1)/9);
    return 0;
}