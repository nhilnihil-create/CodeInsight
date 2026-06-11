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
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> P(N+1);
    REP(i,1,N+1) {
        cin >> P[i].first;
        P[i].second = i;
    }
    ASC(P);

    multiset<ll> S;
    S.insert(0); S.insert(0);
    S.insert(N+1); S.insert(N+1);

    // wi < xi < i < yi < zi
    ll wi, xi, yi, zi;
    ll sum = 0;
    for(ll j=N; j>=1; --j) {
        ll i = P[j].second;
        auto itr = S.lower_bound(i); 
        --itr; --itr; wi = *itr;
        ++itr; xi = *itr;
        ++itr; yi = *itr;
        ++itr; zi = *itr;
        S.insert(i);
        sum += P[j].first * ((xi-wi)*(yi-i) + (i-xi)*(zi-yi));
    }

    PR(sum);

    return 0;
}

/*



*/