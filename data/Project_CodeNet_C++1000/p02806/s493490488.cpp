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
ll countDigit(ll n) { return floor(log10(n) + 1); } 
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

ll nCrModp(ll n, ll r, ll p)
{
    ll C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

int main()
{
    ll N;
    cin >> N;
    vector<pair<string, ll>> p(N);
    rep(i, N) {
        string str;
        ll tmp;
        cin >> str >> tmp;
        p[i] = pair<string, ll>(str, tmp);
    }
    string X;
    cin >> X;
    ll cnt = 0;
    bool flag = false;
    rep(i, N) {
        if (flag) {
            cnt += p[i].second;
        }
        if (X == p[i].first) {
            flag = true;
        } 
    }
    print(cnt);
    return 0;
}