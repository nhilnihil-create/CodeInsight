#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i_len=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back
#define mp make_pair

int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i,0,N) {
        cin >> S[i];
        sort(ALL(S[i]));
    }
    map<string,ll> C;
    ll cnt = 0;
    REP(i,0,N) ++C[S[i]];
    FORR(c,C) cnt += c.second * (c.second - 1) / 2;
    PR(cnt);

    return 0;
}

/*



*/