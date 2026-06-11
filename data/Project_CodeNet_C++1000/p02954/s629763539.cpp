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
    S += "*";

    vector<pair<char,ll>> P;
    char c = 'R';
    ll cnt = 1;
    REP(i,1,N+1) {
        if(S[i] == c) ++cnt;
        else {
            P.pb({c, cnt});
            c = (c == 'L' ? 'R' : 'L');
            cnt = 1;
        }
    }

    vec C(N, 0);
    ll prev = 0;
    // true R->R L->L
    // false R->L L->R
    ll pos = 0, n;
    FORR(p,P) {
        n = p.second;
        pos += n;
        if(p.first == 'R') {
            C[pos-1] += (n + 1) / 2;
            C[pos] += n / 2;
        }
        else {
            C[pos-n-1] += n / 2;
            C[pos-n] += (n + 1) / 2;
        }
    }

    REP(i,0,N) PS(C[i]);
    PR("");

    return 0;
}

/*

RRLLLLRLRRLL

R2 L4 R1 L1 R2 L2

*/