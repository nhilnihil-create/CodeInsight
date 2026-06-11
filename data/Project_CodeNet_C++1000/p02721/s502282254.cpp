#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

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
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    S = " " + S;

    vec L, R;
    REP(i,1,N+1) {
        if(S[i] == 'o') {
            L.pb(i);
            i += C;
        }
    }
    REP(i,1,N+1) {
        if(S[N-i+1] == 'o') {
            R.pb(N-i+1);
            i += C;
        }
    }
    REV(R);

    ll M = MIN(SZ(L),SZ(R));
    if(M == K) { 
        REP(i,0,MIN(SZ(L),SZ(R))) {
            if(L[i] == R[i]) PR(L[i]);
        }
    }

    return 0;
}

/*



*/