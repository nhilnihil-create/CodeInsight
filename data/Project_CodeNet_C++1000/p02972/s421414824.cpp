#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)
#define fi first
#define se second

using ll = long long;
using v_int = std::vector<int>;
using v2_int = std::vector<v_int>;
using v_ll = std::vector<ll>;
using v2_ll = std::vector<v_ll>;
using v_string = std::vector<std::string>;
using v_bool = std::vector<bool>;
using v2_bool = std::vector<v_bool>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const double PI = 3.1415926535897932;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll MOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p)
{
    return o << "{" << p.first << "," << p.second << "}";
}

template<typename T, typename U, typename V> inline
ostream& operator<<(ostream &o, tuple<T,U,V> &p)
{
    return o << "{" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << "}";
}

template<typename T> inline
istream& operator>>(istream &is, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) {
        is >> v[i]; 
    }
    return is;
}

template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &v)
{
    int len = (int)v.size();
    for(int i = 0; i < len; i++) { 
        os << v[i];
        if(i != len-1) { os << ","; } 
    } 
    return os;
}

template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }

template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

void solve(int n, v_int &a) 
{
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            a[i] += 1;
            if(i * i != n) { 
                a[n/i] += 1;
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;

    v_int a(n+1);
    irep(i, n) {
        cin >> a[i+1];
    }
    
    v_int sum(n+1);
    v_int b(n+1);
    
    int m = 0;
    for(int i = n; i > 0; i--) {
        if(sum[i]%2 != a[i]) {
            solve(i, sum);
            b[i] = 1;
            m++;
        }
    }
    
    cout << m << endl;
    for(int i = 1; i <= n; i++) {
        if(b[i]) {
            cout << i << " ";
        }
    }
    
    return 0;
}


/*atcoder*/
