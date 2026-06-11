#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
//#define int long long

struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
}IoSetup;

typedef long long ll;
typedef pair < int , int >  pii;
static const signed int INF = 0x3f3f3f3f;
static const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static const signed int SMOD = 1000000007;
static const signed int NMOD = 998244353;
static const signed int dx[]={1,0,-1,0,1,1,-1,-1};
static const signed int dy[]={0,-1,0,1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T&b){if(a<b)return(a=b,1);return 0;}
template<class T>bool chmin(T &a, const T&b){if(b<a)return(a=b,1);return 0;}


signed main() {

    ll n, k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    int logK = 1;

    while((1LL << logK) < k) logK++;
    // doubling[i][j] := j番目から2^i 進んだ町
    vector<vector<int>> doubling(logK, vector<int>(n));

    for(int i = 0; i < n; i++) {
        doubling[0][i] = a[i];
    }

    for(int i = 0; i < logK - 1; i++) {
        for(int j = 0; j < n; j++) {
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
        }
    }

    int now = 0;

    for(int i = 0; k > 0; i++) {
        if(k & 1) now = doubling[i][now];
        k >>= 1;
    }

    cout << now + 1 << endl;

    return 0;
}
