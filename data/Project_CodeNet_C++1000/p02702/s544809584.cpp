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
#define pb push_back

int main()
{
    string S;
    cin >> S;
    ll N = SZ(S);

    vec T(N+1, 0);
    ll p = 1;
    for(ll i=N-1; i>=0; --i) {
        T[i] = (T[i+1] + (S[i] - '0') * p) % 2019; 
        p = (p * 10) % 2019;
    }
    
    ll cnt = 0;
    map<ll,ll> C;
    REP(i,0,N+1) ++C[T[i]];
    FORR(c,C) cnt += c.second * (c.second - 1) / 2;
    PR(cnt);

    return 0;
}

/*



*/