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


ll modpow(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    ll t = modpow(a, n >> 1, m);
    t = t * t % m;
    if(n & 1) t = t * a % m;
    return t; 
}


int main()
{
    string L;
    cin >> L;
    ll N = SZ(L);
    L = "0" + L;

    mat dp(N+1, vec(2, 0));
    dp[0][0] = 1;

    REP(i,1,N+1) {
        if(L[i] == '0') {
            dp[i][0] = dp[i-1][0] % MOD;
            dp[i][1] = (dp[i-1][1] * 3) % MOD;
        }
        else {
            dp[i][0] = (dp[i-1][0] * 2) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 3) % MOD;
        }
    }

    PR((dp[N][0]+dp[N][1])%MOD);

    /*
    ll sum = 0, c1 = 0, i = 1;
    while(i <= N) {
        while(L[i] == '0') ++i;
        if(L[i] == '1') {
            sum = (sum + (modpow(3, N-i, MOD) * modpow(2, c1, MOD)) % MOD) % MOD;
            ++c1;
            ++i;
        }
    }
    sum = sum + modpow(2, c1, MOD);

    PR(sum);
    */
   
    return 0;
}

/*



*/