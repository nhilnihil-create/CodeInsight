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
    ll N, K;
    cin >> N >> K;
    vec A(N);
    REP(i,0,N) cin >> A[i];

    if(N == 1) PR(0);
    else {
        vec L(N, 0), R(N, 0);
        REP(i,0,N) {
            for(ll j=i-1; j>=0; --j) {
                if(A[j] < A[i]) ++L[i];
            }
            REP(j,i+1,N) {
                if(A[i] > A[j]) ++R[i];
            }
        }
        ll sumL = 0, sumR = 0;
        REP(i,0,N) {
            sumL = (sumL + L[i]) % MOD;
            sumR = (sumR + R[i]) % MOD;
        }
        sumL = (sumL * (((K * (K-1)) / 2) % MOD)) % MOD;
        sumR = (sumR * (((K * (K+1)) / 2) % MOD)) % MOD;
        PR((sumL+sumR)%MOD);
    }
    
    return 0;
}

/*



*/