#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

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
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;

    ll sum = 0;
    map<char,char> kachi;
    map<char,ll> score;
    kachi['r'] = 'p';
    kachi['s'] = 'r';
    kachi['p'] = 's';
    kachi['*'] = '*';
    score['r'] = R;
    score['s'] = S;
    score['p'] = P;
    REP(i,0,K) T += '*';

    string U;
    REP(i,0,K) {
        sum += score[kachi[T[i]]];
        U += kachi[T[i]];
    }
    REP(i,K,N) {
        if(kachi[T[i]] != U[i-K]) {
            sum += score[kachi[T[i]]];
            U += kachi[T[i]];
        }
        else if(T[i] == kachi[T[i+K]]) U += kachi[kachi[T[i]]];
        else U += T[i];
    }
    PR(sum);

    return 0;
}

/*
2275 2106 615
rspssprspsppprpsrpspr
prsrrsprsrssspsrpsrsp
r7 s9 p5


*/