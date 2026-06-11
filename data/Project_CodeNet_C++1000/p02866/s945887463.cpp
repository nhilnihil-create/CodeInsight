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
const ll MOD = 998244353;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p)
{
    return o << "{" << p.first << "," << p.second << "}";
}

template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &v)
{
    int len = v.size();
    for(int i = 0; i < len; i++) { 
        os << v[i];
        if(i != len-1) { os << ","; } 
    } 
    return os;
}

template<typename T>
T ModPow(T s, T n)
{
    T res = 1;

    while(n) {
        if (n & 1) { 
            res *= s;
            res %= MOD;
        }
        s *= s;
        s %= MOD;
        n >>= 1;
    }
    return res;
}

int main(void)
{
    int n;
    cin >> n;

    v_ll d(n);
    v_ll edge(n+1);
    ll max_d = 0;

    irep(i, n) {
        cin >> d[i];
        edge[d[i]]++;
        max_d = max(max_d, d[i]);
    }

    if(d[0] != 0 || edge[0] != 1) { cout << 0 << endl; return 0; } 
    
    ll ans = 1;

    for(int i = 2; i <= max_d; i++) {
        ans *= ModPow(edge[i-1], edge[i]);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}

/*atcoder*/
