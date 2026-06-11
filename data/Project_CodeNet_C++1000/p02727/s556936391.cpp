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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vec P(A), Q(B), R(C);
    REP(i,0,A) cin >> P[i];
    REP(i,0,B) cin >> Q[i];
    REP(i,0,C) cin >> R[i];

    DESC(P); DESC(Q); ASC(R);
    while(SZ(P) > X) P.pop_back();
    while(SZ(Q) > Y) Q.pop_back();
    REV(P); REV(Q);

    ll x = 0, y = 0;
    while(SZ(R) > 0) {
        x = MIN(x,X-1);
        y = MIN(y,Y-1);
        ll p = P[x], q = Q[y];
        ll r = R.back(); R.pop_back();
        if(p <= q && q <= r) {
            P[x] = r;
            ++x;
        }
        else if(p <= r && r <= q) {
            P[x] = r;
            ++x;
        }
        else if(q <= p && p <= r) {
            Q[y] = r;
            ++y;
        }
        else if(q <= r && r <= p) {
            Q[y] = r;
            ++y;
        }
    }
    
    ll sum = 0;
    REP(i,0,X) sum += P[i];
    REP(i,0,Y) sum += Q[i];
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