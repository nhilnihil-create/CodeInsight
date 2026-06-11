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
#define eb emplace_back

int main()
{
    ll N, K;
    cin >> N >> K;
    mat G(N);
    REP(i,0,N-1) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        G[a].eb(b);
        G[b].eb(a);
    }

    if(K == 1) {
        if(N == 1) PR(1);
        else PR(0);
    }
    else if(K == 2) {
        if(N <= 2) PR(2);
        else PR(0);
    }
    else {
        vec P(K-1, 1);
        REP(i,1,K-1) P[i] = (P[i-1] * (K-i-1)) % MOD; // = (K-2)_P_i = (K-2) * ... * (K-i-1)
        ll cnt = K, d = 0, c;
        queue<ll> Q;
        vec F(N, false);
        Q.push(0);
        F[0] = true;
        while(!Q.empty()) {
            ll v = Q.front(); Q.pop();
            c = 0;
            FORR(nv,G[v]) {
                if(!F[nv]) {
                    Q.push(nv);
                    F[nv] = true;
                    ++c;
                }
            }
            ++d;
            if(d == 1) {
                if(K-1 < c) {
                    cnt = 0;
                    break;
                }
                else {
                    REP(i,0,c) cnt = (cnt * (K-1-i)) % MOD;
                }
            }
            else {
                if(K-2 < c) {
                    cnt = 0;
                    break;
                }
                else {
                    cnt = (cnt * P[c]) % MOD;
                }
            }
        }
        PR(cnt);
    }

    return 0;
}

/*



*/