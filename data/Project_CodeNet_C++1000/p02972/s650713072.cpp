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
    ll N;
    cin >> N;
    vec a(N+1);
    REP(i,1,N+1) cin >> a[i];

    vec b(N+1, 0);
    ll sum;
    for(ll i=N; i>=1; --i) {
        sum = 0;
        for(ll j=i+i; j<=N; j+=i) sum = (sum + b[j]) % 2;
        b[i] = (sum + a[i]) % 2;
    }
    ll M = 0;
    REP(i,1,N+1) M += b[i];
    PR(M);
    REP(i,1,N+1) {
        if(b[i] == 1) PR(i);
    } 

    return 0;
}

/*



*/