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

bool solve(string S, ll A, ll C)
{
    bool f = true;
    ll c = 0;
    REP(i,A,C) {
        if(S[i] == '#') ++c;
        else c = MAX(c-1,0);
        if(c == 2) {
            f = false;
            break;
        }
    }
    return f;
}


int main()
{
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    S = "." + S;

    ll f;
    if(A < B && B < D && D < C) {
        f = false;
        ll b = 0;
        REP(i,B,D+1) {
            if(S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') {
                f = true;
                S[i] = '#';
                b = i;
                break;
            }
            f &= solve(S, A, C);
            S[b] = '.';
            f &= solve(S, b, D);
        }
    }
    else {
        f = solve(S, B, D);
        f &= solve(S, A, C);
    }
    if(f) PR("Yes");
    else PR("No");
    

    return 0;
}

/*



*/