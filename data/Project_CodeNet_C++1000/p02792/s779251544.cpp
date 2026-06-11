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

ll msd(ll n)
{
    while(n >= 10) n /= 10;
    return n;
}

int main()
{
    ll N;
    cin >> N;

    mat C(10, vec(10, 0));
    REP(i,1,N+1) ++C[msd(i)][i%10];
    
    ll c = 0;
    REP(i,0,10) {
        REP(j,0,10) c += C[i][j] * C[j][i];
    }
    PR(c);

    return 0;
}

/*

C[i][j] (1 <= i, j <= 9)

A = i*******j
B = j****i

*/