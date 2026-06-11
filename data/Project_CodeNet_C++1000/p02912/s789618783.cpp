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
    ll N, M;
    cin >> N >> M;
    priority_queue<ll> A;
    ll a;
    REP(i,0,N) {
        cin >> a;
        A.push(a);
    }

    REP(i,0,M) {
        a = A.top(); A.pop();
        A.push(a/2);
    }

    ll sum = 0;
    while(!A.empty()) {
        a = A.top(); A.pop();
        sum += a;
    }
    PR(sum);

    return 0;
}

/*



*/