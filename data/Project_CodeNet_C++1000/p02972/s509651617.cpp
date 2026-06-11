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
    ll N;
    cin >> N;
    vec A(N+1, 0);
    REP(i,1,N+1) cin >> A[i];

    vector<bool> F(N+1, false);
    ll M = 0;
    for(ll i=N; i>=1; --i) {
        ll c = 0;
        for(ll j=2*i; j<=N; j+=i) c += F[j];
        F[i] = (c % 2 != A[i]);
        M += F[i];
    }
    
    PR(M);
    REP(i,1,N+1) {
        if(F[i]) PS(i);
    }
    PR("");

    return 0;
}

/*



*/