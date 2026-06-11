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
    mat V(M);
    REP(i,0,N) {
        ll a, b;
        cin >> a >> b;
        if(a <= M) V[M-a].pb(b);
    }

    priority_queue<ll> Q;
    ll sum = 0;
    for(ll i=M-1; i>=0; --i) {
        FORR(b,V[i]) Q.push(b);
        if(!Q.empty()) {
            sum += Q.top();
            Q.pop();
        }
    }    

    PR(sum);

    return 0;
}

/*



*/