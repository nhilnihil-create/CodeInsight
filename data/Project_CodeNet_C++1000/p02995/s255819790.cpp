#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<math.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

#define fi first
#define se second

using namespace std;

using ll = long long;
using v_int = vector<int>;
using v2_int = vector<v_int>;
using v_ll = vector<ll>;
using v2_ll = vector<v_ll>;
using v_string = vector<string>;
using v_bool = vector<bool>;
using v2_bool = vector<v_bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

const double PI = 3.1415926535897932;
const int INF = (int)2e9;
const ll LINF = (ll)2e18;
const ll MOD = 1000000007;
const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p) {
    return o << "{" << p.first << "," << p.second << "}";
}
template<typename T> inline
istream& operator>>(istream &is, vector<T> &vec) {
    for(auto &v : vec) { is >> v; }
    return is;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &vec) {
    for(auto &v : vec) { os << v << ",";}
    return os;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<vector<T> > &mat) {
    for(auto &row : mat) { os << row << endl; }
    return os;
}

template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }
template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }

template<typename T>
T lcm(T a, T b) { return a*(b/gcd(a,b)); }

int main(void)
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll b_mod_c = b / c;
    ll b_mod_d = b / d;
    ll a_mod_c = (a-1) / c;
    ll a_mod_d = (a-1) / d;
    ll b_mod_cd = b / lcm(c,d);
    ll a_mod_cd = (a-1) / lcm(c,d);

    ll ans = b-a+1;
    ans -= (b_mod_d - a_mod_d) + (b_mod_c - a_mod_c) - (b_mod_cd - a_mod_cd);
    cout << ans << endl;
    return 0;
} /*atcoder*/

