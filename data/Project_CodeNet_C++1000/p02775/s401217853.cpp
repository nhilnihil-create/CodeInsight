#include "bits/stdc++.h"
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, a, b) for(int i=(b-1);i>=(a);i--)
#define REP(i, n) for(int i=0; i<(n); i++)
#define RREP(i, n) for(int i=(n-1); i>=0; i--)
#define REP1(i, n) for(int i=1; i<=(n); i++)
#define RREP1(i, n) for(int i=(n); i>=1; i--)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE_SORT(l) sort(ALL(l)); l.erase(unique(ALL(l)), l.end());
#define CONTAIN(a, b) find(ALL(a), (b)) != (a).end()
#define out(...) printf(__VA_ARGS__)
#if DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) /* ... */
#endif
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
void _OUT() {}; template<class H, class... T> void _OUT(H &h, T &... t) { cout<<' '<<h; _OUT(t...); };
template<class H, class... T> void _P(H &h, T &... t) { cout<<h; _OUT(t...); };
#define _PN(...) _P(__VA_ARGS__); cout << endl;

void solve();
signed main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

/*================================*/
#if DEBUG
#define SIZE 100
#else
#define SIZE 2234560
#endif

string N;
// i桁目/繰り下がりあり→最小の枚数
int DP[SIZE][2];

void solve() {
    cin>>N;
    REP(i,SIZE)REP(j,2)DP[i][j]=INT_MAX;
    int n = N[0]-'0';
    DP[0][1]=1+(10-n);
    DP[0][0]=n;
    REP1(i,N.size()-1) {
        int n = N[i]-'0';
        chmin(DP[i][0], DP[i-1][0]+n);
        chmin(DP[i][1], DP[i-1][0]+1+(10-n));
        chmin(DP[i][0], DP[i-1][1]+n);
        chmin(DP[i][1], DP[i-1][1]+(10-n)-1);
    }
    int i = N.size()-1;
    _PN(min(DP[i][0],DP[i][1]));
}


