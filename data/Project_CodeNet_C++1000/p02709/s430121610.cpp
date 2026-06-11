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
#define SIZE 2222
#endif

int N;
vector<int> A(SIZE);
vector<pair<int,int>> B;
// 大きい順にi番目まで/左からj個埋まっている→最大の嬉しさ
int DP[SIZE][SIZE];

void solve() {
    cin>>N;
    REP(i,N) {
        cin>>A[i];
        B.push_back({A[i],i});
    }
    sort(ALL(B));
    reverse(ALL(B));
    DP[0][1] = abs(B[0].second-0)*B[0].first;
    DP[0][0] = abs(B[0].second-(N-1))*B[0].first;
    REP1(i,N-1)REP(j,i+1) {
        // 右へ寄せる
        chmax(DP[i][j], DP[i-1][j]+abs(B[i].second-(N-1-(i-j)))*B[i].first);
        // 左へ寄せる
        chmax(DP[i][j+1], DP[i-1][j]+abs(B[i].second-(j))*B[i].first);
    }
    int ans = 0;
    REP(i,N)chmax(ans,DP[N-1][i]);
    _PN(ans);
}

