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

ll mid(vec A)
{
    ll N = SZ(A) - 1;
    if(N % 2 == 1) return A[(N+1)/2];
    else return A[N/2] + A[N/2+1];
}

int main()
{
    ll N;
    cin >> N;
    vec A(N+1, 0), B(N+1, 0);
    REP(i,1,N+1) cin >> A[i] >> B[i];
    
    ASC(A); ASC(B);
    ll midA = mid(A);
    ll midB = mid(B);

    PR(midB-midA+1);


    return 0;
}

/*



*/