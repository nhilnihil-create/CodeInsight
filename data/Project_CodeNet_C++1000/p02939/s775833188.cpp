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
    string S;
    cin >> S;

    ll N = SZ(S);
    vec A(N, 0);
    
    A[0] = 1;
    if(N >= 2) A[1] = (S[0] == S[1]) ? 1 : 2;
    if(N >= 3) A[2] = (S[0] == S[1] || S[1] == S[2]) ? 2 : 3;
    if(N >= 4) {
        REP(i,3,N) A[i] = (S[i-1] == S[i]) ? (A[i-3] + 2) : (A[i-1] + 1);
    }
    
    PR(A[N-1]);

    return 0;
}

/*



*/