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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vec P(A), Q(B), R(C);
    REP(i,0,A) cin >> P[i];
    REP(i,0,B) cin >> Q[i];
    REP(i,0,C) cin >> R[i];

    DESC(P);
    DESC(Q);
    DESC(R);

    vec S;
    REP(i,0,X) S.pb(P[i]);
    REP(i,0,Y) S.pb(Q[i]);
    REP(i,0,C) S.pb(R[i]);

    DESC(S);
    ll sum = 0;
    REP(i,0,X+Y) sum += S[i];
    PR(sum);
    
    return 0;
}

/*

p q r -> p = r
p r q -> p = r
q p r -> q = r
q r p -> q = r
r p q -> x
r q p -> x

*/