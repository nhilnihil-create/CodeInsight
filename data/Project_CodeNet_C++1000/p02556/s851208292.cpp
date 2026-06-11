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
    vector<pll> P(N);
    REP(i,0,N) cin >> P[i].first >> P[i].second;

    pll p1 = P[0], p2 = P[0], p3 = P[0], p4 = P[0];
    ll k1 = -INF, k2= -INF, k3 = -INF, k4 = -INF;
    REP(i,0,N) {
        if(-P[i].first + P[i].second > k1) {
            k1 = -P[i].first + P[i].second;
            p1 = P[i];
        }
        if(P[i].first + P[i].second > k2) {
            k2 = P[i].first + P[i].second;
            p2 = P[i];
        }
        if(P[i].first - P[i].second > k3) {
            k3 = P[i].first - P[i].second;
            p3 = P[i];
        }
        if(-P[i].first - P[i].second > k4) {
            k4 = -P[i].first - P[i].second;
            p4 = P[i];
        }
    }

    vec D(6);
    D[0] = abs(p1.first-p2.first) + abs(p1.second-p2.second);
    D[1] = abs(p1.first-p3.first) + abs(p1.second-p3.second);
    D[2] = abs(p1.first-p4.first) + abs(p1.second-p4.second);
    D[3] = abs(p2.first-p3.first) + abs(p2.second-p3.second);
    D[4] = abs(p2.first-p4.first) + abs(p2.second-p4.second);
    D[5] = abs(p3.first-p4.first) + abs(p3.second-p4.second);
    
    DESC(D);
    PR(D[0]);

    return 0;
}

/*



*/