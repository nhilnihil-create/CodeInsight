#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cout << #x << " = " << (x) << endl;
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

const int MAX_ROW = 110; //to be set
const int MAX_COL = 100100; //to be set
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

//どう掃き出そうが結果は同じ

void GaussJordan(BitMatrix &A, bool is_extended = false) {
    vector<bool> used(A.H, 0);
    for(int col = 0; col < A.W; ++col) {
        if(is_extended && col == A.W - 1) break;
        int pivot = -1;
        for(int row = 0; row < A.H; ++row) {
            if(A[row][col]) {
                if(used[row]) continue;
                pivot = row;//上位の桁で偶数個あるものを優先的に奇数、奇数に分けたいので、（つまり、0 0 0 0...0 1となって欲しくない）上位の桁から優先的にpivotになるようにする
                break;
            }
        }
        if(pivot == -1) continue;
        //swap(A[rank], A[pivot]);
        for(int row = 0; row < A.H; ++row) {
            if(row != pivot && A[row][col]) A[row] ^= A[pivot];
        }
        used[pivot] = 1;
    }
}

void solve() {
	int n; cin >> n;
    ll a[100100];
    rep(i, n) {
        cin >> a[i];
    }
    vector<bool> cannot(110, 0);
    ll res = 0;
    BitMatrix B(61, n + 1);
    for(int d = 60; d >= 0; --d) {
        int cnt = 0;
        rep(i, n) {
            if(a[i] & (1LL << d)) cnt ++;
        }
        if(cnt == 0) {
            cannot[d] = 1;
            continue;
        }
        if(cnt % 2 == 1) {
            cannot[d] = 1;
            res += (1LL << d);
            continue;
        }
        rep(i, n) {
            if(a[i] & (1LL << d)) {
                B[60 - d][i] = 1;
            }
        }
        B[60 - d][n] = 1;
    }
    GaussJordan(B, true);
    for(int d = 60; d >= 0; --d) {
        if(cannot[d]) continue;
        bool ok = false;
        rep(i, n) if(B[60 - d][i]) ok = true;
        if(!B[60 - d][n]) ok = true; //掃き出しの結果として=1が=0になることもある！
        
        if(ok) res += (1LL << d) * 2;
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}