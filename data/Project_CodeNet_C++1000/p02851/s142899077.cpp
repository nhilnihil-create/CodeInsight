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

int main()
{
    ll N, K;
    cin >> N >> K;
    vec A(N);
    REP(i,0,N) cin >> A[i];

    vec csum(N+1, 0);
    REP(i,0,N) csum[i+1] = (csum[i] + A[i]) % K;
    
    ll cnt = 0;
    map<ll,ll> S;
    queue<ll> Q;
    REP(i,0,N+1) {
        ll t = (csum[i] - i) % K;
        t += t < 0 ? K : 0;
        cnt += S[t];
        ++S[t];
        Q.push(t);
        if(SZ(Q) >= K) {
            --S[Q.front()];
            Q.pop();
        }
    }

    PR(cnt);

    return 0;
}

/*



*/