#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i,0,H) cin >> S[i];

    mat L(H, vec(W, 0));
    mat R(H, vec(W, 0));
    mat U(H, vec(W, 0));
    mat D(H, vec(W, 0));
    ll c;

    REP(i,0,H) {
        c = 0;
        REP(j,0,W) {
            if(S[i][W-1-j] == '.') ++c;
            else c = 0;
            L[i][W-1-j] = c;
        } 
    }
    REP(i,0,H) {
        c = 0;
        REP(j,0,W) {
            if(S[i][j] == '.') ++c;
            else c = 0;
            R[i][j] = c;
        } 
    }
    REP(j,0,W) {
        c = 0;
        REP(i,0,H) {
            if(S[H-1-i][j] == '.') ++c;
            else c = 0;
            U[H-1-i][j] = c;
        } 
    }
    REP(j,0,W) {
        c = 0;
        REP(i,0,H) {
            if(S[i][j] == '.') ++c;
            else c = 0;
            D[i][j] = c;
        } 
    }

    ll m = 0;
    REP(i,0,H) {
        REP(j,0,W) {
            m = MAX(m,L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
        }
    }
    PR(m);

    return 0;
}

/*



*/