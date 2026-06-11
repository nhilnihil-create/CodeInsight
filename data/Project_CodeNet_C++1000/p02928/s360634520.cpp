#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

const double PI = 3.1415926535897932;
const int INF = (int)1e9;
const ll LINF = 1e18;
const int IMOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

int solve(v_int &a)
{
    int rtn = 0;

    irep(i, a.size()) {
        irep2(j, i+1, a.size()-1) {
            if(a[i] > a[j]) {
                rtn++;
            }
        }
    }
    return rtn;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) { 
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    v_int a(n);
    v_int kaidan(4);

    irep(i, n) {
        cin >> a[i];
    }
    
    irep2(i, 1, 3) { 
        v_int b; 
        irep(j, i) {
            irep(k, n) {
                b.push_back(a[k]);
            }        
        }
        kaidan[i] = solve(b);
        //cout << kaidan[i] << endl;
    }

    ll start = kaidan[2] - kaidan[1];
    ll diff = kaidan[3]-2*kaidan[2]+kaidan[1];
    ll ans = 2*start;
    ans += (((k-2) % IMOD) * diff) % IMOD; 
    ans *= (k-1) % IMOD;
    ans %= IMOD;
    ans *= modinv(2, IMOD);
    ans += kaidan[1];
    ans %= IMOD;
    cout << ans << endl;

    return 0;
}
/** atcoder **/

