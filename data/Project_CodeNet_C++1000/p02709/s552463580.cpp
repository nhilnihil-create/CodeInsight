#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ALL(x) (x).begin(), (x).end()

const ll INF = 1001001001;
const int MOD = 1000000007;
const int MAX_N = 101010;

// A:array of pair, N:size of array
void sort_second(vector<pair<ll, ll>> &A, int N);
// a^n
ll a_n(ll a, ll n);
// make vector of (n!)%MOD, (n!)^(-1)%MOD to calculate nCk
void factorial_map(vector<ll> &n, vector<ll> &ninv);
// a^(-1) % MOD 
ll inv(ll a);
// map of prime factorization
void prime_map(map<ll, ll> &a, ll n);
//list of prime (is_prime.size() = n + 1, primes.size() = 0)
void prime_list(ll n, vector<ll> &primes, vector<bool> &is_prime);
// get gcd from prime map
ll gcd_map(map<ll, ll> a, map<ll, ll> b);
// get lcm from prime map
ll lcm_map(map<ll, ll> a, map<ll, ll> b);
// get gcd
ll my_gcd(ll a, ll b);
// calculate nCk
ll nCk(ll n, ll k);
// get abs
ll my_abs(ll a);
// z-algorithm (s.size() == a.size())
void z_algorithm(string s, vector<int> &a);

class Unionfind {
    public:
        vector<ll> par, siz, rank;
        Unionfind();
        ll root(ll x);
        void merge(ll x, ll y);
        bool issame(ll x, ll y);
        ll size(ll x);
};

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for(ll i=0; i <n; i++) {
        ll tmp;
        cin >> tmp;
        a.push_back(make_pair(tmp, i+1));
    }
    sort(ALL(a), greater<pair<ll, ll>>());

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1*INF));
    dp[0][0] = 0;

    for(ll i=1; i<=n; i++) {
        for(ll x = 0; x <= i; x++) {
            ll y = i-x, left = -1*INF, right = -1*INF;
            if(x>0) {
                left = dp[x-1][y] + a[i-1].first*my_abs(a[i-1].second-x);
            }
            if(y>0) {
                right = dp[x][y-1] + a[i-1].first*my_abs(a[i-1].second-(n-(y-1)));
            }
            dp[x][y] = max(left, right);
        }
    }

    ll ans = -1*INF;
    for(ll i=0; i<=n; i++) {
        if(ans < dp[i][n-i]) ans = dp[i][n-i];
    }

    cout << ans << endl;

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}