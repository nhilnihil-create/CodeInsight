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
    mat A(3, vec(3));
    REP(i,0,3) REP(j,0,3) cin >> A[i][j];
    ll N;
    cin >> N;
    vec B(N);
    REP(i,0,N) cin >> B[i];

    bool f;
    REP(i,0,3) REP(j,0,3) {
        f = false;
        REP(k,0,N) {
            if(A[i][j] == B[k]) {
                f = true;
                break;
            }
        }
        A[i][j] = (ll)f;
    }

    f = false;
    if(A[0][0] && A[0][1] && A[0][2]) f = true;
    if(A[1][0] && A[1][1] && A[1][2]) f = true;
    if(A[2][0] && A[2][1] && A[2][2]) f = true;
    if(A[0][0] && A[1][0] && A[2][0]) f = true;
    if(A[0][1] && A[1][1] && A[2][1]) f = true;
    if(A[0][2] && A[1][2] && A[2][2]) f = true;
    if(A[0][0] && A[1][1] && A[2][2]) f = true;
    if(A[0][2] && A[1][1] && A[2][0]) f = true;
    
    if(f) PR("Yes");
    else PR("No");

    return 0;
}

/*



*/