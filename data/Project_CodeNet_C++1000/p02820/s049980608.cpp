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
    ll N, K, R, S, P;
    string T;
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;

    ll sum = 0;
    map<char,char> kachi;
    kachi['r'] = 'p'; kachi['s'] = 'r'; kachi['p'] = 's', kachi['*'] = '*';
    map<char,ll> score;
    score['r'] = R; score['s'] = S; score['p'] = P; score['*'] = 0;
    vector<vector<char>> U(N/K+2, vector<char>(K, '*')), V(N/K+2, vector<char>(K, '*'));
    
    REP(i,0,N) U[i/K][i%K] = T[i];
    REP(i,0,K) {
        V[0][i] = kachi[U[0][i]];
        sum += score[V[0][i]];
    }
    
    REP(i,1,N/K+1) {
        REP(j,0,K) {
            if(V[i-1][j] == kachi[U[i][j]]) V[i][j] = U[i+1][j];
            else {
                V[i][j] = kachi[U[i][j]];
                sum += score[V[i][j]];
            }
        }
    }
    PR(sum);
    
    return 0;
}

/*



*/