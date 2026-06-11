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
    ll S;
    cin >> S;

    mat C(2001, vec(2001, 0));
    C[0][0] = 1;
    REP(i,1,2001) {
        C[i][0] = 1;
        REP(j,1,2001) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }

    ll sum = 0;
    REP(i,1,S/3+1) {
        if(S >= i*2+1) sum = (sum + C[S-2*i-1][i-1]) % MOD;
    }
    PR(sum);

    return 0;
}

/*



*/