#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i##_len=(n);(i)<(i##_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define _PR(x) cout << (x) << endl
#define _PS(x) cout << (x) << " "
#define SZ(x) ((int)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back

int main()
{
    ll N, K;
    cin >> N >> K;
    ll L = (N-1) * (N-2) /2;
    ll c = L;
    if(K > L) _PR(-1);
    else {
        _PR(N-1+L-K);
        REP(i,2,N+1) cout << 1 << " " << i << endl;
        REP(i,2,N) {
            REP(j,i+1,N+1) {
                if(c > K) cout << i << " " << j << endl;
                --c;
            }
        }
    }

    return 0;
}

/*



*/