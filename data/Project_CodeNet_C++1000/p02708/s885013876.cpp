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
    ll N, K;
    cin >> N >> K;

    vec csum(N+1, 0);
    REP(i,1,N+1) csum[i] = csum[i-1] + i;

    ll min, max, cnt = 0;
    REP(i,K,N+1) {
        min = csum[i-1];
        max = csum[N] - csum[N-i];
        cnt = (cnt + max - min + 1) % MOD;
    }
    PR(cnt+1);

    return 0;
}

/*

0 ... N -> k ko

*/