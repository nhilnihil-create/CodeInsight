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

ll solve(ll N, ll P, string S)
{
    if (P == 2 || P == 5) {
        long long res = 0;
        for (int i = 0; i < N; ++i) if ((S[N-i-1]-'0') % P == 0) res += N-i;
        return res;
    }
    vector<long long> val(P, 0);
    long long tenfactor = 1;
    long long cur = 0;
    val[cur]++;
    for (int i = 0; i < N; ++i) {
        cur = (cur + (S[N-i-1]-'0') * tenfactor) % P;
        tenfactor = (tenfactor * 10) % P;
        val[cur]++;
    }
    long long res = 0;
    for (int p = 0; p < P; ++p) res += val[p] * (val[p] - 1) / 2;
    return res;
}


int main()
{
    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    ll cnt = 0;
    if(P == 2 || P == 5) {
        REP(i,0,N) {
            if((S[N-i-1] - '0') % P == 0) cnt += N - i;
        }
    }
    else {
        vec C(N+1, 0);
        ll d = 1;
        REP(i,0,N) {
            C[i+1] = (C[i] + (S[N-i-1] - '0') * d) % P;
            d = (d * 10) % P;
        }
        map<ll,ll> M;
        REP(i,0,N+1) ++M[C[i]];
        FORR(m,M) cnt += (m.second - 1) * m.second / 2;
    }

    PR(cnt);

    return 0;
}

/*


*/