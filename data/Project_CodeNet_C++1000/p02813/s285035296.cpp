#include <bits/stdc++.h>
//#include<iostream>
//#include<vector>
//#include<map>
//#include<math.h>
//#include<algorithm>

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define rrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

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

int main(void)
{
    int n;
    cin >> n;
    v_int p(n), q(n);
    cin >> p >> q;

    v_int idx(n), org(n);
    rep(i,n) { 
        idx[i] = i; 
        org[i] = i+1;
    }
    
    int ans[2] = {0,0}, cnt = 1;
    do {
        v_int r(n);
        rep(i,n) {
            r[i] = org[idx[i]];    
        }
        rep(i,2) {
            bool ok = true;
            rep(j,n) {
                if(i==0) {
                    if(r[j] != p[j]) { ok = false; }
                } else {
                    if(r[j] != q[j]) { ok = false; }
                }
            }
            if(ok) {
                ans[i] = cnt;
            }
        }
        cnt++;
    } while(next_permutation(idx.begin(), idx.end()));
    cout << abs(ans[0]-ans[1]) << endl;
    return 0;
} /*atcoder*/
