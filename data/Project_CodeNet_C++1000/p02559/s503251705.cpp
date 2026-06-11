#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


// 参考 : http://hos.ac/slides/20140319_bit.pdf
struct FenwickTree_sum { // 0-indexed !
    vector<ll> v;
    const int n;

    FenwickTree_sum(int _n) : n(_n) {
        v.resize(n+1, 0);
    }

    ll sum(int i) { // 区間 [0,i] の総和
        i++;
        ll res = 0;
        for(int x = i; x > 0; x -= x & -x) {
            res += v[x];
        }
        return res;
    }

    ll sum(int i, int j) { // 区間 [i,j] の総和
        return sum(j) - sum(i-1);
    }

    ll lower_bound(ll w) { // v1 + v2 + ⋯ + vx ≧ w となる最小の x
        if(w <= 0) return -1;
        ll x = 0;
        int k = 1;
        while(k*2 <= n) k *= 2;
        for(; k > 0; k /= 2) {
            if(x+k <= n && v[x+k] < w) {
                w -= v[x+k];
                x += k;
            }
        }
        return x;
    }

    void add(int i, ll w) { // i番目に w を加算
        i++;
        for(int x = i; x <= n; x += x & -x) {
            v[x] += w;
        }
    }
};


int main(){
    
    int n, q;
    cin >> n >> q;

    FenwickTree_sum ft(n);
    rep(i,n) {
        int a;
        cin >> a;
        ft.add(i,a);
    }

    rep(i,q) {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 0) ft.add(a,b);
        if(type == 1) cout << ft.sum(a,b-1) << endl;
    }
}