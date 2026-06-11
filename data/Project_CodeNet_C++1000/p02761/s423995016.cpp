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
    ll N, M;
    cin >> N >> M;
    vec s(M), c(M);
    REP(i,0,M) {
        cin >> s[i] >> c[i];
        --s[i];
    }

    vec D(N, -1);
    bool f = true;
    REP(i,0,M) {
        if(s[i] < N && (D[s[i]] == -1 || D[s[i]] == c[i])) D[s[i]] = c[i];
        else {
            f = false;
            break;
        } 
    }

    if(N > 1 && D[0] == 0) f = false;
    if(N == 1 && D[0] == -1) D[0] = 0;
    if(N > 1) {
        if(D[0] == -1) D[0] = 1;
        REP(i,1,N) if(D[i] == -1) D[i] = 0;
    }

    if(f) REP(i,0,N) cout << D[i];
    else cout << -1;
    cout << endl;

    return 0;
}

/*



*/